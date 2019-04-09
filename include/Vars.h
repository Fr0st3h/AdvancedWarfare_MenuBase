int HostNumber;//Host client number.
bool isLoaded;//Detects if menu is loaded (Checks if menu stored its huds)
bool isOpen[12];//The 12 Represents "12 Clients"
bool isVer[12];//Detects if player has menu access!
int Scroll[12];//scroll # you're on
int MaxScroll[12];//Max amount of scrolls within the sub menu
const char* Menu[12];//Sub menu you're in.
int SelectedClient;//Determins the Client Selected in Players Menu
char* Status[12];//Detects players Menu access level status, Example: VIP, Admin, Co-Host, Host