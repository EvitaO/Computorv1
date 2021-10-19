#include "validate.hpp"
#include "header.hpp"

validate::validate(){}

validate::validate(std::string str){
	_input = str;
	_equal = 1;
	_nbr = 0;
}

validate::validate(validate const & src){
	*this =src;
}

validate::~validate(){}

validate &	validate::operator=(validate const & src){
	_input = src._input;
	_reducedform = src._reducedform;
	_chunks = src._chunks;
	_order = src._order;
	_degree = src._degree;
	_nbr = src._nbr;
	_equal = src._equal;
	return *this;
}

void		validate::setup(){
	createChunks();
	controlChunks();
	setDegree();
	createReduced();
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
			exp = stoi(stringNumber(input, i + 2));
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
		_equal *= -1;
	}
	if (input[i] == '+' && input[i + 1] == ' ')
		i = i + 2;
	else if (input[i] == '-' && input[i + 1] == ' ') {
		i = i + 2;
		sign *= -1;
	}
	return i * sign * _equal;
}

int		validate::saveNbr(std::string input, int i, int sign){
	std::string number;
	if (isdigit(input[i]) || input[i] == '.'){
		number = stringNumber(input, i);
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
	std::vector<std::pair<float, int> >::iterator	x = std::max_element(_order.begin(), _order.end(), compare);
	_degree = _order[std::distance(_order.begin(), x)].second;
}	

int			validate::getDegree() const{
	return _degree;
}

void		validate::addpair(float n, int exp){
	for (int i = 0; i < _order.size(); i++){
		if (_order[i].second == exp){
			_order[i].first += n;
			break;
		}
		else if (i == _order.size() - 1){
			_order.push_back(std::make_pair(n, exp));
			break;
		}
	}
	if (_order.size() == 0)
		_order.push_back(std::make_pair(n, exp));
}

void		validate::createReduced(){
	std::stringstream	s;
	for(int i = 0; i < _order.size(); i++){
		if (_order[i].first != 0){
			std::string st = std::to_string(_order[i].first);
			if (st[0] == '-')
				s << "- " << _order[i].first * -1 << " * X^" << _order[i].second;
			else
				s << _order[i].first << " * X^" << _order[i].second;
			if (i + 1 < _order.size() && _order[i + 1].first != 0){
				std::string st2 = std::to_string(_order[i+1].first);
				if (st2[0] != '-')
					s << " +";
				s << " ";
			}
		}
	}
	if (s.str().size() == 0){
		s << "0";
		_degree = 0;
	}
	s << " = 0\n";
	_reducedform = s.str();
}

std::string	validate::getReduced() const{
	return _reducedform;
}

float		validate::getFloat(int exp){
	for(int i = 0; i < _order.size(); i++){
		if (_order[i].second == exp)
			return _order[i].first;
	}
	return 0;
}

std::ostream &			operator<<(std::ostream & o, validate const & src){	
	o << "Reduced form: " << src.getReduced();
	o << "Polynomial degree: " << src.getDegree();
	if (src.getDegree() > 2){
		o << "\nThe polynomial degree is strictly greater than 2, I can't solve.";
		throw std::runtime_error("");
	}
	return o;
}
