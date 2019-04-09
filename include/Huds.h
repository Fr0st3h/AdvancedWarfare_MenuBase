union hudelem_color_t
    {
        struct
        {
            unsigned char r;
            unsigned char g;
            unsigned char b;
            unsigned char a;
        };
        int rgba;
    };
 
    struct hudelem_s
    {
        short targetent1;
        short targetent2;
        int font;
        int alignOrg;
        int alignScreen;
        float x;
        float y;
        float z;
        int type;
        float FontScale;
        int FromFontScale;
        int FontScaleStartTime;
        int FontScaleTime;
        hudelem_color_t color;
        hudelem_color_t fromColor;
        int fadeStartTime;
        int fadeTime;
        int label;
        int Width;
        int Height;
        int MaterialIndex;
        int fromWidth;
        int fromHeight;
        int moveStartTime;
        int moveTime;
        float fromX;
        float fromY;
        int fromAlignOrg;
        int fromAlignScreen;
        int scaleStartTime;
        int scaleTime;
        int time;
        int duration;
        float value;
        int text;
        float sort;
        hudelem_color_t glowColor;
        int fxBirthTime;
        int fxLetterTime;
        int fxDecayStartTime;
        int fxDecayDuration;
        int soundID;
        int unknown;
        int flags;
    };
 
    struct game_hudelem_s
    {
        hudelem_s elem;
        int ClientNum;
        int team;
        int archived;
        int showInKillcam;
    };



//Functions

typedef struct hudelem_s *hudelem_t;
typedef struct game_hudelem_s *game_hudelem_t;

void(*HudElem_DestroyAll)() = (void(*)())0x71BDE0;

#define Leveltime *(int*)(0x6395980 + 0x4EC)


typedef game_hudelem_t (*HudElem_Alloc_t)(int clientNum, int teamNum);
HudElem_Alloc_t HudElem_Alloc = (HudElem_Alloc_t)0x71BC00;

game_hudelem_t SetShader(int client, const char* shader, int Width, int Height, float x, float y, unsigned char r, unsigned char g, unsigned char b, unsigned char a){
    game_hudelem_t elem = HudElem_Alloc(client, 0);
    elem->ClientNum = client;
    elem->elem.type = 4;
    elem->elem.MaterialIndex = G_MaterialIndex(shader);
    elem->elem.Width = Width;
    elem->elem.Height = Height;
    elem->elem.x = x;
    elem->elem.y = y;
    elem->elem.alignOrg = 0;
    elem->elem.color.r = r;
    elem->elem.color.g = g;
    elem->elem.color.b = b;
    elem->elem.color.a = a;
    elem->elem.targetent1 = 1;
    elem->elem.targetent2 = 1;
    return elem;
}
game_hudelem_t SetText(int client, char* text, float x, float y, int Allign, float fontScale, char font, unsigned char r, unsigned char g, unsigned char b, unsigned char a, unsigned char glowR, unsigned char glowG, unsigned char glowB, unsigned char glowA){
    game_hudelem_t elem = HudElem_Alloc(client, 0);
    elem->ClientNum = client;
    elem->elem.type = 1;
    elem->elem.font = font;
    elem->elem.FontScale = fontScale;
    if(Allign != 0){
        elem->elem.alignOrg = 5;
        elem->elem.alignScreen = Allign;
        elem->elem.x = x;
        elem->elem.y = y;
    }else{ elem->elem.x = x; elem->elem.y = y;}
    elem->elem.color.r = r;
    elem->elem.color.g = g;
    elem->elem.color.b = b;
    elem->elem.color.a = a;
    elem->elem.glowColor.r = glowR;
    elem->elem.glowColor.g = glowG;
    elem->elem.glowColor.b = glowB;
    elem->elem.glowColor.a = glowA;
    elem->elem.text = G_LocalizedStringIndex(text);
    elem->elem.targetent1 = 1;
    elem->elem.targetent2 = 1;
    return elem;
}
void MoveOverTime(game_hudelem_t elem, float time, float x, float y) 
{ 
    elem->elem.fromX = elem->elem.x;
    elem->elem.fromY = elem->elem.y;
    elem->elem.moveStartTime = Leveltime;
    elem->elem.moveTime = time;
    elem->elem.x = x;
    elem->elem.y = y;
}
void SetY(game_hudelem_t elem, float y) 
{ 
    elem->elem.y = y;
}
void ChangeText(game_hudelem_t elem, const char* text) 
{ 
     elem->elem.text = G_LocalizedStringIndex(text);
}
void scaleOverTime(game_hudelem_t elem, float time, float width, float height){

	elem->elem.fromWidth = elem->elem.Width;
	elem->elem.fromHeight = elem->elem.Height;
	elem->elem.scaleStartTime = Leveltime;
	elem->elem.scaleTime = time;
	elem->elem.Width = width;
	elem->elem.Height = height;
}
void scaleOverTime2(game_hudelem_t elem, float time, float width, float height){

	elem->elem.fromWidth = width;
	elem->elem.fromHeight = height;
	elem->elem.scaleStartTime = Leveltime;
	elem->elem.scaleTime = time;
}

void FadeOverTime(game_hudelem_t elem, int time, float red, float green, float blue, float alpha)
{
    elem->elem.fromColor = elem->elem.color;
    elem->elem.fadeStartTime = Leveltime;
    elem->elem.fadeTime = time;
    elem->elem.color.r = red;
    elem->elem.color.g = green;
    elem->elem.color.b = blue;
    elem->elem.color.a = alpha;
}

void SetColor(game_hudelem_t elem, char r, char g, char b, char a, bool IsGlow)
{
    if (IsGlow) {
        elem->elem.glowColor.r = r;
        elem->elem.glowColor.g = g;
        elem->elem.glowColor.b = b;
        elem->elem.glowColor.a = a;
    }
    else {
        elem->elem.color.r = r;
        elem->elem.color.g = g;
        elem->elem.color.b = b;
        elem->elem.color.a = a;
    }

}

void TypeWriterText(game_hudelem_t elem, char* Text, float YPos, float FontScale)
{
    ChangeText(elem, Text);
    SetColor(elem, 0, 255, 0, 255, true);
    elem->elem.fxBirthTime = Leveltime;
    elem->elem.fxLetterTime = 100;
    elem->elem.fxDecayStartTime = 7000;
    elem->elem.fxDecayDuration = 1000;
    elem->elem.flags |= 0x4;
}