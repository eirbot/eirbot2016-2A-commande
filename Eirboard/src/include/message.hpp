/*****************************************************/
/*               Message Architecture                */
/*                   STM32F429ZI                     */
/*                                                   */
/*****************************************************/

#pragma once

#include <base/integer.hpp>

class Message
{
public:
	Message();
	Message(u32 boardID, u32 function, u32 data);
	Message(char* boardID, char* function, char* data);

	void setBoardID(const char* boardID);
	u32 getBoardID();
	void setFunction(const char* function);
	u32 getFunction();
	u32 getParityFunction();
	void setData(const char* data);
	u32 getData();
	u32 getParityData();

	u32 sendMessage();
	void receiveMessage(u32 msg);

	bool isBoard();
	bool isFunction();
	bool isParityFunction();
	bool isData();
	bool isParityData();
	~Message();

private:
	u32 m_boardID;
	u32 m_function;
	u32 m_parityFunction;
	u32 m_data;
	u32 m_parityData;
};