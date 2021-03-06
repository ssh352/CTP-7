// testTraderApi.cpp : 定义控制台应用程序的入口点。
//
#include ".\ThostTraderApi\ThostFtdcTraderApi.h"
#include "TraderSpi.h"

// UserApi对象
CThostFtdcTraderApi* pUserApi;

//char  FRONT_ADDR[] = "tcp://180.168.146.187:10000";   // 前置地址
//TThostFtdcBrokerIDType	BROKER_ID = "9999";		    // 经纪公司代码
//TThostFtdcInvestorIDType INVESTOR_ID = "101042";	    // 注意输入你自己的simnow仿真投资者代码
//TThostFtdcPasswordType  PASSWORD = "518888";			// 注意输入你自己的simnow仿真用户密码

char  FRONT_ADDR[] = "tcp://61.152.165.100:41201";	    // 前置地址       国贸期货-快期 测试成功
TThostFtdcBrokerIDType	BROKER_ID = "0187";				// 经纪公司代码   国贸期货-快期 测试成功
TThostFtdcInvestorIDType INVESTOR_ID = "28006311";	    // 注意输入你自己的投资者代码
TThostFtdcPasswordType  PASSWORD = "518888";			// 注意输入你自己的用户密码

/*
char  FRONT_ADDR[] = "tcp://116.228.171.216:41205";		// 前置地址      新湖期货-快期 测试成功
TThostFtdcBrokerIDType	BROKER_ID = "6090";				// 经纪公司代码  新湖期货-快期 测试成功 
TThostFtdcInvestorIDType INVESTOR_ID = "10501951";	    // 注意输入你自己的投资者代码
TThostFtdcPasswordType  PASSWORD = "202031";			// 注意输入你自己的用户密码
*/

TThostFtdcInstrumentIDType INSTRUMENT_ID = "MA801";	    // 合约代码 ，注意与时俱进改变合约ID,避免使用过时合约
TThostFtdcDirectionType	DIRECTION = THOST_FTDC_D_Sell;	// 买卖方向
TThostFtdcPriceType	LIMIT_PRICE = 2700;				    // 价格

// 请求编号
int iRequestID = 0;

void main(void)
{

	// 初始化UserApi
	pUserApi = CThostFtdcTraderApi::CreateFtdcTraderApi();			// 创建UserApi
	CTraderSpi* pUserSpi = new CTraderSpi();
	pUserApi->RegisterSpi((CThostFtdcTraderSpi*)pUserSpi);			// 注册事件类
	pUserApi->SubscribePublicTopic(TERT_RESTART);					// 注册公有流
	pUserApi->SubscribePrivateTopic(TERT_RESTART);					// 注册私有流
	pUserApi->RegisterFront(FRONT_ADDR);							// connect
	pUserApi->Init();

	pUserApi->Join();
//	pUserApi->Release();
}