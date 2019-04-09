typedef int (*G_MaterialIndex_t)(const char *Material);
G_MaterialIndex_t G_MaterialIndex = (G_MaterialIndex_t)0x43C4A0;

typedef int (*G_LocalizedStringIndex_t)(const char *Text);
G_LocalizedStringIndex_t G_LocalizedStringIndex = (G_LocalizedStringIndex_t)0x442410;


typedef int (*Key_IsDown_t)(int ClientNum, int ButtonEnum);
Key_IsDown_t Key_IsDown = (Key_IsDown_t)0x6267F0;

typedef bool (*Dvar_GetBool_t)(const char* dvar);
Dvar_GetBool_t Dvar_GetBool = (Dvar_GetBool_t)0x92D450;

typedef const char* (*Dvar_GetString_t)(const char* dvar);
Dvar_GetString_t Dvar_GetString = (Dvar_GetString_t)0x92D530;


typedef void (*SV_GameSendServerCommand_t)(int clientNum, int type, const char *text);
SV_GameSendServerCommand_t SV_GameSendServerCommand = (SV_GameSendServerCommand_t)0x89CD80;

TYPE_BEGIN(struct gentity_s, 0x2E0);
TYPE_FIELD(int32_t health, 0x1D0);
TYPE_END();

TYPE_BEGIN(struct gclient_s,  0x5780);
TYPE_FIELD(int32_t health, 0x19B);
TYPE_FIELD(char name[32], 0x5070);
TYPE_FIELD(uint32_t mflags, 0x5324);
TYPE_FIELD(float origin[3], 0x2C);
TYPE_END();


typedef struct gentity_s *gentity_t;
typedef struct gclient_s *gclient_t;

gentity_t gentity = (gentity_t)0x64293D0;
gclient_t gclient = (gclient_t)0x659C1CC;