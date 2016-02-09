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
	void (bool board);
	bool isBoard();
	void (bool function);
	bool isFunction();
	void (bool parity);
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

int Message::getBoardID()
{

}

int Message::getFunction()
{

}
bool Message::isBoard()
{

}
bool Message::isFunction()
{

}
bool Message::isParity()
{

}