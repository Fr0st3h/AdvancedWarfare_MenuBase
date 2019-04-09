void iPrintln(int client, const char* msg) {
	char buf[100];
	snprintf(buf, 100, "f \"%s%s", msg, "\"");
	SV_GameSendServerCommand(client, 0, buf);
}


void iPrintlnBold(int client, const char* msg) {
	char buf[100];
	snprintf(buf, 100, "c \"%s%s", msg, "\"");
	SV_GameSendServerCommand(client, 0, buf);
}

void GiveHostOnly(int Host)
{
	isVer[Host] = true;
	Status[Host] = "HOST";
}
void UpdateScroll(int client)
{
	scaleOverTime(Scrollbar[client], 105, 175, 15);
    MoveOverTime(Scrollbar[client], 105, 385, 78.21 + (Scroll[client] * 16.79)); 
}

char playerBuffer[1000];
char* ArrayForNames()
{
	strcpy(playerBuffer, "");
	for (int i = 0; i < 12; i++){
	gclient_t pName = &gclient[i];
	if(!strcmp(pName->name, ""))
	{
		
		char* ch = "Not Connected\n";
		char chArray[1000];
		sprintf(chArray, "%s", ch);
		strcat(playerBuffer, chArray);
	}
	else
	{

			char* ch = pName->name;
			char chArray[1000];
			sprintf(chArray, "%s\n", ch);
			strcat(playerBuffer, chArray);
		
	}
	 
	}
	return playerBuffer;
}


//Menu Verification:
void GiveVIP(int SelectedClient, int ClientGiving)
{
	if(SelectedClient != 0){
		isVer[SelectedClient] = true;
		Status[SelectedClient] = "VIP";
		iPrintln(SelectedClient,"Menu Access Level: ^5VIP ^7Given.");
		iPrintln(ClientGiving, "Menu Access Level: ^5VIP ^7Given to client.");
	}else{
		iPrintln(ClientGiving, "^1Error^7: Cannot remove menu from host!");
	}
}
void GiveAdmin(int SelectedClient, int ClientGiving)
{
	if(SelectedClient != 0){
		isVer[SelectedClient] = true;
		Status[SelectedClient] = "ADMIN";
		iPrintln(SelectedClient,"Menu Access Level: ^2Admin ^7Given.");
		iPrintln(ClientGiving, "Menu Access Level: ^2Admin ^7Given to client.");
	}else{
		iPrintln(ClientGiving, "^1Error^7: Cannot remove menu from host!");
	}
}
void GiveCoHost(int SelectedClient, int ClientGiving)
{
	if(SelectedClient != 0){
	isVer[SelectedClient] = true;
	Status[SelectedClient] = "Co-Host";
	iPrintln(SelectedClient, "Menu Access Level: ^1Co-Host ^7Given.");
	iPrintln(ClientGiving, "Menu Access Level: ^1Co-Host ^7Given to client.");
	}else{
		iPrintln(ClientGiving, "^1Error^7: Cannot remove menu from host!");
	}
}
void RemoveMenuAccess(int SelectedClient, int ClientGiving)
{
	if(SelectedClient != 0){
		if(isOpen[SelectedClient])
	{
		OpenClose(SelectedClient);
	}
	isVer[SelectedClient] = false;
	iPrintln(SelectedClient, "Menu Access Level: ^1Removed");
	iPrintln(ClientGiving,"Menu Access: ^1Removed ^7from client!");
	}else{
		iPrintln(ClientGiving, "^1Error^7: Cannot remove menu from host!");
	}
}

//Client List:
bool GiveGod[12];
void GiveGodMode(int client, int Giver)
{
	gentity_t Cli = &gentity[client];
	if(!GiveGod[client])
	{
		Cli->health = 0xFFFF;
		iPrintln(client, "God Mode: [^2ON^7]");
		iPrintln(Giver, "God Mode: Given to client!");
		GiveGod[client] = true;
	}
	else
	{
		Cli->health = 0x0064;
		iPrintln(client, "God Mode: [^1OFF^7]");
		iPrintln(Giver, "God Mode: Removed from client!");
		GiveGod[client] = false;
	}
}