/*
	Copyright (C) 2003-2005 Daniel Muller, dan at verliba dot cz
	Copyright (C) 2006-2014 Verlihub Project, devs at verlihub-project dot org

	Verlihub is free software; You can redistribute it
	and modify it under the terms of the GNU General
	Public License as published by the Free Software
	Foundation, either version 3 of the license, or at
	your option any later version.

	Verlihub is distributed in the hope that it will be
	useful, but without any warranty, without even the
	implied warranty of merchantability or fitness for
	a particular purpose. See the GNU General Public
	License for more details.

	Please see http://www.gnu.org/licenses/ for a copy
	of the GNU General Public License.
*/

#include "ccommandcollection.h"
#include "i18n.h"
#include <iostream>

namespace nVerliHub {
	namespace nCmdr {

cCommandCollection::cCommandCollection(void *owner) :
cObj("cCmdr"),
mOwner(owner)
{}

cCommandCollection::~cCommandCollection()
{}

void cCommandCollection::Add(cCommand *command)
{
	if (command) {
		mCmdList.push_back(command);
		command->mCmdr = this;
	}
}

int cCommandCollection::ParseAll(const string &commandLine, ostream &os, void *options)
{
	cCommand *Cmd = this->FindCommand(commandLine);

	if (Cmd != NULL)
		return (int)this->ExecuteCommand(Cmd, os, options);
	else
		return -1;
}

cCommand *cCommandCollection::FindCommand(const string &commandLine)
{
	tCmdList::iterator it;

	for (it = mCmdList.begin(); it != mCmdList.end(); ++it) {
		cCommand *Cmd = *it;
		if (Cmd && Cmd->ParseCommandLine(commandLine)) return Cmd;
	}

	return NULL;
}

bool cCommandCollection::ExecuteCommand(cCommand *command, ostream &os, void *options)
{
	if (command->TestParams()) {
		command->Execute(os, options);
		//if (command->Execute(os, options))
			//os << _("[OK]");
		//else
			//os << _("[ERROR]");

		return true;
	} else {
		os << _("Command parameters error") << ":\r\n";
		command->GetSyntaxHelp(os);
		return false;
	}
}

void cCommandCollection::List(ostream *os)
{
	for (tCmdList::iterator it = mCmdList.begin(); it != mCmdList.end(); ++it) {
		if (*it) {
			(*os) << "\r\n";
			(*it)->Describe(*os);
		}
	}
}

void cCommandCollection::InitAll(void *data)
{
	for (tCmdList::iterator it = mCmdList.begin(); it != mCmdList.end(); ++it) {
		if (*it) (*it)->Init(data);
	}
}
	}; //namespace nCmdr
}; // namespace nVerliHub
