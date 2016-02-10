/*****************************************************/
/*               Message Architecture                */
/*                   STM32F429ZI                     */
/*                                                   */
/*****************************************************/

class Message
{
public:
	Message();
	void setBoardID(int boardID);
	int getBoardID();
	void setFunction(int function);
	int getFunction();
	void setData(int data);
	int getData();
	void setParity(int parity);
	int getParity();

	bool isBoard();
	bool isFunction();
	bool isData();
	bool isParity();

private:
	int m_boardID;
	int m_function;
	int m_data;
	int m_parity;
};

Message::Message()
{
	m_boardID = 0;
	m_function = 0;
	m_data = 0;
	m_parity = 0;
}

void Message::setBoardID(int boardID)
{
	m_boardID = boardID;
}

int Message::getBoardID()
{
	return m_boardID;
}

void Message::setFunction(int function)
{
	m_function = function;
}

int Message::getFunction()
{
	return m_function;
}

void Message::setData(int data)
{
	m_data = data;
}

int Message::getData()
{
	return m_data;
}

void Message::setParity(int parity)
{
	m_parity = parity;
}

int Message::getParity()
{
	return m_parity
}

bool Message::isBoard()
{
	if (m_boardID = "0010") // A modifier
		return true;
	else
		return false;
}

bool Message::isFunction()
{
	switch (m_function)
	{
		case "000000000000001" : // A modifier
			return true;
			break;

		case "000000000000010" : // A modifier
			return true;
			break;

		default :
			return false;
	}
}

bool Message::isData()
{
	switch (m_data)
	{
		case "000010100101001" : // A modifier
			return true;
			break;

		case "000011000100010" : // A modifier
			return true;
			break;

		case "100111010100000" : // A modifier
			return true;
			break;		

		default :
			return false;
	}	
}

bool Message::isParity()
{
	if (dataParity (m_data) == m_parity)
		return true;
	else
		return false;
}