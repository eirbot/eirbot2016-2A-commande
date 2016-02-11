/*****************************************************/
/*               Message Architecture                */
/*                   STM32F429ZI                     */
/*                                                   */
/*****************************************************/

class Message
{
public:
	Message();
	void setBoardID(char* boardID);
	u32 getBoardID();
	void setFunction(char* function);
	u32 getFunction();
	void setParityFunction(char* parityFunction);
	u32 getParityFunction();
	void setData(char* data);
	u32 getData();
	void setParityData(char* parityData);
	u32 getParityData();

	bool isBoard();
	bool isFunction();
	bool isParityFunction();
	bool isData();
	bool isParityData();

private:
	u32 m_boardID;
	u32 m_function;
	u32 m_parityFunction;
	u32 m_data;
	u32 m_parityData;
};

Message::Message()
{
	m_boardID = s2bin ("0000");
	m_function = s2bin ("0000000");
	m_parity = s2bin ("0");
	m_data = s2bin ("0000000000000000000");
	m_parity = s2bin ("0");
}

void Message::setBoardID(char* boardID)
{
	m_boardID = s2bin (boardID)
}

u32 Message::getBoardID()
{
	return m_boardID;
}

void Message::setFunction(char* function)
{
	m_function = s2bin (function);
}

u32 Message::getFunction()
{
	return m_function;
}

void Message::setParityFunction(char* parityFunction)
{
	m_parityFunction = s2bin (parityFunction);
}

u32 Message::getParityFunction()
{
	return m_parityFunction
}

void Message::setData(char* data)
{
	m_data = s2bin (data);
}

u32 Message::getData()
{
	return m_data;
}

void Message::setParityData(char* parityData)
{
	m_parityData = s2bin (parityData);
}

u32 Message::getParityData()
{
	return m_parityData
}

bool Message::isBoard()
{
	if (bitsCount (m_boardID) == 1)
	{
		if (m_boardID == s2bin ("0010")) // Correspond à Eirboard
			return true;
		else
			return false;
	}
	else
		return false;
}

bool Message::isFunction()
{
	if (bitsCount (m_function) == 1)
	{
		switch (m_function)
		{
			case s2bin ("0000000") : // Correspond à la fonction
				return true;
				break;

			case s2bin ("0000001") : // Correspond à la fonction
				return true;
				break;

			default :
				return false;
		}
	}
	else
		return false;
}

bool Message::isParityFunction()
{
	if (dataParity (m_function) == m_parityFunction)
		return true;
	else
		return false;
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

bool Message::isParityData()
{
	if (dataParity (m_data) == m_parityData)
		return true;
	else
		return false;
}