bool startReverse = false;
void doAnimation(int client){
    scaleOverTime(Scrollbar[client], 100, 125, 5);
    MoveOverTime(Scrollbar[client], 100, 410, 83 + (Scroll[client] * 16.79)); 
    if(Scrollbar[client]->elem.Width == 125){
        startReverse = true;
    }
    if(Scrollbar[client]->elem.Width < 175 && startReverse){
        scaleOverTime(Scrollbar[client], 100, 175, 15);
        MoveOverTime(Scrollbar[client], 100, 385, 78.21 + (Scroll[client] * 16.79)); 
    }
}
void LoadSub(int client, const char* Sub)
{
    ChangeText(CurrMenu[client], Sub);
	if(Sub == "Main Menu")
	{
		Scroll[client] = 1;//Scroll number
		MaxScroll[client] = 2;//max amount of scrolls aloud in sub menu
		Menu[client] = Sub;
		ChangeText(Options[client], "Sub Menu 1\nClient List");
	}else if(Sub == "Sub Menu 1")
	{
		Scroll[client] = 1;
		MaxScroll[client] = 12;
		Menu[client] = Sub;
		ChangeText(Options[client], "Option 1\nOption 2\nOption 3\nOption 4\nOption 5\nOption 6\nOption 7\nOption 8\nOption 9\nOption 10\nOption 11\nOption 12");
	}else if(Sub == "Client List")
	{
		Scroll[client] = 1;
		MaxScroll[client] = 12;
		Menu[client] = Sub;
		ChangeText(Options[client], ArrayForNames());
	}
	else if(Sub == "Client List Mods")
	{
		Scroll[client] = 1;
		MaxScroll[client] = 5;
		Menu[client] = Sub;
		ChangeText(Options[client], "Give God Mode\nGive VIP\nGive Admin\nGive Co-Host\nRemove Menu Access");
	}
    doAnimation(client);
}

void Toggle(int client, const char* Menu, int scroll)
{   
    doAnimation(client);
	if(Menu == "Main Menu")
	{
		if(scroll == 1) LoadSub(client, "Sub Menu 1");
		if(scroll == 2) 
		{
			if(Status[client] == "HOST") LoadSub(client, "Client List");
			else iPrintln(client, "^1Error: Must have higher access level to use this option!");
		}
	}else if(Menu == "Client List")
	{
		if(scroll == 1)
		{
			SelectedClient = 0;
			LoadSub(client, "Client List Mods");
		}
		if(scroll == 2)
		{
			SelectedClient = 1;
			LoadSub(client, "Client List Mods");
		}
		if(scroll == 3)
		{
			SelectedClient = 2;
			LoadSub(client, "Client List Mods");
		}
		if(scroll == 4)
		{
			SelectedClient = 3;
			LoadSub(client, "Client List Mods");
		}
		if(scroll == 5)
		{
			SelectedClient = 4;
			LoadSub(client, "Client List Mods");
		}
		if(scroll == 6)
		{
			SelectedClient = 5;
			LoadSub(client, "Client List Mods");
		}
		if(scroll == 7)
		{
			SelectedClient = 6;
			LoadSub(client, "Client List Mods");
		}
		if(scroll == 8)
		{
			SelectedClient = 7;
			LoadSub(client, "Client List Mods");
		}
		if(scroll == 9)
		{
			SelectedClient = 8;
			LoadSub(client, "Client List Mods");
		}
		if(scroll == 10)
		{
			SelectedClient = 9;
			LoadSub(client, "Client List Mods");
		}
		if(scroll == 11)
		{
			SelectedClient = 10;
			LoadSub(client, "Client List Mods");
		}
		if(scroll == 12)
		{
			SelectedClient = 11;
			LoadSub(client, "Client List Mods");
		}
	}
	else if(Menu == "Client List Mods")
	{
		if(scroll == 1) GiveGodMode(SelectedClient, client);
		if(scroll == 2) GiveVIP(SelectedClient, client);
		if(scroll == 3) GiveAdmin(SelectedClient, client);
		if(scroll == 4) GiveCoHost(SelectedClient, client);
		if(scroll == 5) RemoveMenuAccess(SelectedClient, client);
	}
}

