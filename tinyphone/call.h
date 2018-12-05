#pragma once

#pragma once

#ifndef CALL_HEADER_FILE_H
#define CALL_HEADER_FILE_H

#include <pj/config_site.h>
#include <pjsua2.hpp>
#include <iostream>
#include <boost/foreach.hpp>
#include "enum.h"
#include "events.h"
#include "utils.h"

using namespace std;
using namespace pj;

namespace tp {
	BETTER_ENUM(HoldStatus, int32_t, NOT_IN_HOLD = 0x00, LOCAL_HOLD = 0x01, REMOTE_HOLD = 0x02);
}

class SIPAccount;

class SIPCall : public Call
{
private:
	SIPAccount *account;

public:
	SIPCall(Account &acc, int call_id = PJSUA_INVALID_ID)
		: Call(acc, call_id)
	{
		account = (SIPAccount *)&acc;
	}

	SIPAccount* getAccount() {
		return account;
	}

	virtual void onCallState(OnCallStateParam &prm);
	virtual void onCallMediaState(OnCallMediaStateParam &prm);
	virtual bool HoldCall();
	virtual bool UnHoldCall();
	virtual tp::HoldStatus HoldState();
	virtual void onCallEnd();
	virtual void Hangup();

};
 

#endif