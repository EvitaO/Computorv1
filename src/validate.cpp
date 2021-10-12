#include "validate.hpp"

validate::validate(){}

validate::validate(std::string str){
	_input = str;
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
	return *this;
}

void		validate::createChunks(){
	int			pos = 0;
	int			end;
	if (std::count(_input.begin(), _input.end(), '=') != 1)
		throw std::runtime_error("input format is not correct");
	while (_input[pos] != '\0'){
		if (_input.find("^") != std::string::npos){
			end = _input.find("^") + 2;
			_chunks.push_back(_input.substr(pos, end));
			_input.erase(pos, end + 1);
		}
		else if (_input == "= 0")
			break;
		else
			throw std::runtime_error("input format is not correct");
	}
#if 0
	for(int i = 0; i < _chunks.size(); i++){
		std::cout << _chunks[i] << std::endl;
	}
#endif
}

int			validate::checkSigns(std::string input, int i){
	int 	sign = 1;
	if (input[i] == '=' && input[i + 1] == ' '){
		i = i + 2;
		sign *= -1;
	}
	if (input[i] == '+' && input[i + 1] == ' ')
		i = i + 2;
	else if (input[i] == '-' && input[i + 1] == ' ') {
		i = i + 2;
		sign *= -1;
	}
	return i * sign;
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
		else if (input[i] == 'x' && input[i + 1] == '^' && isdigit(input[i + 2]) && input[i + 3] == '\0')
			exp = input[i + 2] - 48;
		else if (input[i] == 'X' && input[i + 1] == '^' && isdigit(input[i + 2]))
			exp = input[i + 2] - 48;
		else{
			throw std::runtime_error("invalid format");
			return;
		}
		i = i + 3;
	}
	addpair(_nbr, exp);
	_nbr = 0;
}

void		validate::controlChunks(){
	for (int i = 0; i < _chunks.size(); i++){
		controlChunk(_chunks[i]);
	}
}

void		validate::setDegree(){
	std::vector<std::pair<float, int> >::iterator	x = std::max_element(_order.begin(), _order.end(), compare);
	_degree = _order[std::distance(_order.begin(), x)].second;
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

void		validate::setup(){
	createChunks();
	controlChunks();
	setDegree();
	createReduced();
}

int			validate::getDegree() const{
	return _degree;
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
