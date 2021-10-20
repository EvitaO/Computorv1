#include "validate.hpp"

validate::validate(){}

validate::validate(std::string str){
	_input = str;
	_equalsign = 1;
	_nbr = 0;
	_degree = 0;
}

validate::validate(validate const & src){
	*this =src;
}

validate::~validate(){}

validate &	validate::operator=(validate const & src){
	_input = src._input;
	_reducedform = src._reducedform;
	_chunks = src._chunks;
	_inputOrder = src._inputOrder;
	_degree = src._degree;
	_nbr = src._nbr;
	_equalsign = src._equalsign;
	return *this;
}

void		validate::setup(){
	createChunks();
	controlChunks();
	createReducedForm();
	setDegree();
}

void		validate::createChunks(){
	int			pos = 0;
	int			end;
	if (std::count(_input.begin(), _input.end(), '=') != 1)
		throw std::runtime_error("input format is not correct");
	while (_input[pos] != '\0'){
		if (_input.find("^") != std::string::npos){
			end = _input.find("^");
			while (_input[end] != ' ' && _input[end] != '\0')
				end++;
			_chunks.push_back(_input.substr(pos, end));
			_input.erase(pos, end + 1);
		}
		else if (atof(&_input[2]) == 0 && isdigit(_input[2]))
			break;
		else
			throw std::runtime_error("input format is not correct");
	}
}

void		validate::controlChunks(){
	for (int i = 0; i < _chunks.size(); i++){
		controlChunk(_chunks[i]);
	}
}

void		validate::controlChunk(std::string input){
	int		sign = 1;
	int		i = 0;
	int		exp = 0;
	
	i = checkSigns(input, i);
	if (i < 0){
		sign = -1;
		i = i * -1;
	}
	i = saveNbr(input, i, sign);
	while (i < input.size()){
		if (input[i] == ' ' && input[i + 1] == '*' && input[i + 2] == ' ');
		else if (charX(input[i]) && input[i + 1] == '^' && isdigit(input[i + 2])){
			exp = stoi(createStringNumber(input, i + 2));
			while (isdigit(input[i+3]))
				i++;
		}
		else{
			throw std::runtime_error("invalid format");
			return;
		}
		i = i + 3;
	}
	addpair(_nbr, exp);
	_nbr = 0;
}

int			validate::checkSigns(std::string input, int i){
	int 	sign = 1;
	if (input[i] == '=' && input[i + 1] == ' '){
		i = i + 2;
		_equalsign *= -1;
	}
	if (input[i] == '+' && input[i + 1] == ' ')
		i = i + 2;
	else if (input[i] == '-' && input[i + 1] == ' ') {
		i = i + 2;
		sign *= -1;
	}
	return i * sign * _equalsign;
}

int		validate::saveNbr(std::string input, int i, int sign){
	std::string number;
	if (isdigit(input[i]) || input[i] == '.'){
		number = createStringNumber(input, i);
		if (input[i] == '.')
			i = i + number.size() - 1;
		else
			i = i + number.size();
		_nbr = atof(number.c_str()) * sign;
	}
	else
		throw std::runtime_error("invalid format");
	return i;
}

void		validate::setDegree(){
	std::string tmp = _reducedform;
	int	index = 0;
	_degree = 0;
	while (tmp[0] && tmp.find("^") != std::string::npos){
		index = tmp.find("^");
		_degree = (_degree < stoi(createStringNumber(tmp, index + 1))) ? stoi(createStringNumber(tmp, index + 1)) : _degree;
		tmp.erase(0, index + 1);
	}
}	

int			validate::getDegree() const{
	return _degree;
}

void		validate::addpair(float n, int exp){
	for (int i = 0; i < _inputOrder.size(); i++){
		if (_inputOrder[i].second == exp){
			_inputOrder[i].first += n;
			break;
		}
		else if (i == _inputOrder.size() - 1){
			_inputOrder.push_back(std::make_pair(n, exp));
			break;
		}
	}
	if (_inputOrder.size() == 0)
		_inputOrder.push_back(std::make_pair(n, exp));
	if (n != 0)
		_degree = (exp > _degree) ? exp : _degree;
}

void		validate::createReducedForm(){
	std::stringstream	s;
	for(int i = 0; i < _inputOrder.size(); i++){
		if (_inputOrder[i].first != 0){
			std::string st = std::to_string(_inputOrder[i].first);
			if (st[0] == '-')
				s << "- " << _inputOrder[i].first * -1 << " * X^" << _inputOrder[i].second;
			else
				s << _inputOrder[i].first << " * X^" << _inputOrder[i].second;
			while (i + 1 < _inputOrder.size() && _inputOrder[i + 1].first == 0)
				i++;
			if (i + 1 < _inputOrder.size()){
				std::string st2 = std::to_string(_inputOrder[i+1].first);
				if (st2[0] != '-')
					s << " +";
				s << " ";
			}
		}
	}
	if (s.str().size() == 0){
		s << "0 * X^" << _degree;
	}
	s << " = 0\n";
	_reducedform = s.str();
}

std::string	validate::getReducedForm() const{
	return _reducedform;
}

float		validate::getFloat(int exp){
	for(int i = 0; i < _inputOrder.size(); i++){
		if (_inputOrder[i].second == exp)
			return _inputOrder[i].first;
	}
	return 0;
}

std::ostream &			operator<<(std::ostream & o, validate const & src){	
	o << "Reduced form: " << src.getReducedForm();
	o << "Polynomial degree: " << src.getDegree();
	if (src.getDegree() > 2){
		o << "\nThe polynomial degree is strictly greater than 2, I can't solve.";
		throw std::runtime_error("");
	}
	return o;
}
