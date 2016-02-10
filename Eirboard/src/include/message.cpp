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
	void setFunction(int msg);
	int getFunction();
	void boolBoard(bool board);
	bool isBoard();
	void boolFunction(bool function);
	bool isFunction();
	void boolParity(bool parity);
	bool isParity();

	private:
	
	int m_boardID;
	int m_msg;
	bool m_board:
	bool m_function;
	bool m_parity;
};

Message::Message()
{
	m_boardID = 0;
	m_msg = 0;
	m_board = false;
	m_function = false;
	m_parity = false;
}

void Message::setBoardID(int boardID)
{
	m_boardID = boardID;
}

int Message::getBoardID()
{
	return m_boardID;
}

void Message::setFunction(int msg)
{
	m_msg = msg;
}

int Message::getFunction()
{
	return m_msg
}

void Message::boolBoard(bool board)
{
	m_board = board;
}

bool Message::isBoard()
{
	return m_board;
}

void Message::boolFunction(bool function)
{
	m_function = function
}

bool Message::isFunction()
{
	return m_function;
}

void Message::boolParity(bool parity)
{
	m_parity = parity;
}

bool Message::isParity()
{
	return m_parity;
}