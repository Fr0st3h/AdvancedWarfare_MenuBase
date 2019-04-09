game_hudelem_t Title[12];//12 = Number of clients
game_hudelem_t Creator[12];//12 = Number of clients
game_hudelem_t Options[12];
game_hudelem_t CurrMenu[12];
game_hudelem_t WelcomeMessage[12];

game_hudelem_t Lines[12][2];//2 = 2 Background
game_hudelem_t Background[12];//2 = 2 Background
game_hudelem_t Scrollbar[12];

void Store(int client){
	Background[client] = SetShader(client, "white", 175, 1080, 0, 500, 0, 0, 0, 200);
	Lines[client][1] = SetShader(client, "white", 3, 1080, 0, 500, 0, 255, 0, 255);
	Lines[client][2] = SetShader(client, "white", 3, 1080, 0, 500, 0, 255, 0, 255);
	Scrollbar[client] = SetShader(client, "white", 175, 15, 0, 500, 0, 255, 0, 255);

	Title[client] = SetText(client, "Menu Base", 410, 10, 0, 1.3f, 6, 255, 255, 255, 0, 0, 255, 0, 255);
	Creator[client] = SetText(client, "By CMTFrosty", 445, 45, 0, 0.8f, 3, 255, 255, 0, 0, 0, 0, 0, 0);
	CurrMenu[client] = SetText(client, "Main Menu", 435, 58, 0, 0.8f, 6, 255, 255, 255, 0, 0, 0, 0, 0);
	Options[client] = SetText(client, "Dont Need To Change", 395, 94, 0, 1.4f, 3, 255, 255, 255, 0, 0, 0, 0, 0);
}

void OpenClose(int client)
{
	
	if(!isOpen[client])
	{
	Background[client]->elem.x = 0;
	Background[client]->elem.y = 500;
	Lines[client][1]->elem.x = 0;
	Lines[client][1]->elem.y = 500;
	Lines[client][2]->elem.x = 0;
	Lines[client][2]->elem.y = 500;
	Scrollbar[client]->elem.x = 0;
	Scrollbar[client]->elem.y = 500;
	scaleOverTime(Background[client], 225, 175, 1080);
	MoveOverTime(Background[client], 225, 385, 0);
	scaleOverTime(Lines[client][1], 225, 3, 1080);
	MoveOverTime(Lines[client][1], 225, 385, 0);
	scaleOverTime(Lines[client][2], 225, 3, 1080);
	MoveOverTime(Lines[client][2], 225, 560, 0);
	scaleOverTime(Scrollbar[client], 225, 175, 15);
	MoveOverTime(Scrollbar[client], 225, 385, 95); 
	
	FadeOverTime(Options[client], 200, 255, 255, 255, 255);
	FadeOverTime(CurrMenu[client], 200, 255, 255, 255, 255);
	FadeOverTime(Title[client], 200, 255, 255, 255, 255);
	FadeOverTime(Creator[client], 200, 255, 255, 0, 255);
		isOpen[client] = true;
	}
	else if(isOpen[client])
	{
	scaleOverTime(Background[client], 500, 175, 1080);
	MoveOverTime(Background[client], 500, 1500, 1920);
	scaleOverTime(Lines[client][1], 225, 3, 1080);
	MoveOverTime(Lines[client][1],  500, 1500, 1920);
	scaleOverTime(Lines[client][2], 225, 3, 1080);
	MoveOverTime(Lines[client][2],  500, 1500, 1920);
	scaleOverTime(Scrollbar[client], 225, 175, 15);
	MoveOverTime(Scrollbar[client],  500, 1500, 1920);

	FadeOverTime(Options[client], 100, 255, 255, 255, 0);
	FadeOverTime(CurrMenu[client], 100, 255, 255, 255, 0);
	FadeOverTime(Title[client], 100, 255, 255, 255, 0);
	FadeOverTime(Creator[client], 100, 255, 255, 0, 0);
	isOpen[client] = false;
		
	}
}