enum Buttons{
    R3 = 0x11,
    DpadRight = 0x017,
    DpadLeft = 0x016,
    DpadDown = 0x015,
    DpadUp = 0x014,
    Square = 0x03,
    L1 = 0x05


};
bool ButtonPressed(int clientIndex, unsigned int Button)
{
	if (Key_IsDown(clientIndex, Button)){
        return true;
    }else{
        return false;
    }	
}
bool cooldown = false;
int cooldownTimer = 0;
void ButtonMonitoring(){
    if(cooldown){
				if(cooldownTimer < 21){
					cooldownTimer += 1;
				}else{
					cooldown = false;
					cooldownTimer = 0;
				}
			}
			for(int i = 0; i < 12; i++)
			{
				if(!isLoaded)
				{
					HostNumber = 0;
					Store(i);
					GiveHostOnly(HostNumber);
					isLoaded = true;
				}
				else
				{
					
					if(ButtonPressed(i, L1) && ButtonPressed(i, R3) && cooldown == false && isVer[i] && !isOpen[i])
					{
						LoadSub(i, "Main Menu");
						cooldown = true;
						OpenClose(0);
					}
					else if(ButtonPressed(i, R3) && cooldown == false && isVer[i] && isOpen[i])
					{
						cooldown = true;
						if(Menu[i] == "Main Menu") OpenClose(i);
						else if(Menu[i] == "Sub Menu 1") { LoadSub(i, "Main Menu"); Scroll[i] = 1; UpdateScroll(i); }
						else if(Menu[i] == "Client List") { LoadSub(i, "Main Menu");  Scroll[i] = 1;UpdateScroll(i); }
						else if(Menu[i] == "Client List Mods") { LoadSub(i, "Client List"); Scroll[i] = 1; UpdateScroll(i); 
						 UpdateScroll(i);}
					}else if(ButtonPressed(i, DpadUp) && cooldown == false && isOpen[i] && isVer[i])
					{
						cooldown = true;					
						Scroll[i]--;
						if(Scroll[i] < 1)
						{
							Scroll[i] = MaxScroll[i];
						}
						UpdateScroll(i);
					}else if(ButtonPressed(i, DpadDown) && cooldown == false && isOpen[i] && isVer[i])
					{
						cooldown = true;					
						Scroll[i]++;
						if(Scroll[i] > MaxScroll[i])
						{
							Scroll[i] = 1;
						}
						UpdateScroll(i);
					}else if(ButtonPressed(i, Square) && cooldown == false && isOpen[i] && isVer[i])
					{
						cooldown = true;
						Toggle(i, Menu[i], Scroll[i]);
					}
				}
			}
}