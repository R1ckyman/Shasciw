#include <string.h>
#include <stdio.h>

#include <switch.h>

#define MAPSIZE 32
#define EACH_TURN 3
#define INVENTORY 10
#define KEYBOARD 40

int k_index = 0;
bool caps = true;
bool debug = true;
bool shoot = false;
int bullets[2] = {0,0};
int maxBullets[2] = {1,1};
int b_dir[4] = {0,0,0,0};

typedef struct Player
{
    int inventory[INVENTORY];
    char letter;
    int healt;
} Player;

bool printKeyboard(bool turn, char keyboard_1[KEYBOARD], char keyboard_2[KEYBOARD]){
    int i;

    u32 kDown = hidKeysDown(CONTROLLER_P1_AUTO);

    if(((kDown & KEY_ZL) && turn) || ((kDown & KEY_ZR) && !turn)){
        caps = !caps;
    }
    if(((kDown & KEY_L) && turn) || ((kDown & KEY_R) && !turn)){
        return true;
    }
    if(((kDown & KEY_DUP) && turn) || ((kDown & KEY_X) && !turn)){
        if(k_index >= 10){
            k_index -= 10;
        }
        else{
            k_index += 30;
        }
    }
    if(((kDown & KEY_DDOWN) && turn) || ((kDown & KEY_B) && !turn)){
        if(k_index <= 29){
            k_index += 10;
        }
        else{
            k_index -= 30;
        }
    }
    if(((kDown & KEY_DLEFT) && turn) || ((kDown & KEY_Y) && !turn)){
        if(k_index == 0 || k_index == 10 || k_index == 20 || k_index == 30){
            k_index += 9;
        }else{
            k_index--;
        }
    }
    if(((kDown & KEY_DRIGHT) && turn) || ((kDown & KEY_A) && !turn)){
        if(k_index == 9 || k_index == 19 || k_index == 29 || k_index == 39){
            k_index -= 9;
        }else{
            k_index++;
        }
    }
    if(turn) printf("\x1b[4;1H\t\t\t\t\t\t\t\t--Choose your letter Player 1--");
    else printf("\x1b[4;1H\t\t\t\t\t\t\t\t--Choose your letter Player 2--");
    printf("\x1b[7;1H\t\t\t\t\t\t\t\t\t");      
    for(i=0;i<KEYBOARD;i++){
        if(caps){
            if(i == k_index){
                printf("\x1b[31m%c \x1b[0m",keyboard_1[i]);
            }else{
                printf("%c ",keyboard_1[i]);
            }
            if(i == 9 || i == 19 || i == 29) printf("\n\t\t\t\t\t\t\t\t\t");
        }
        else{
            if(i == k_index){
                printf("\x1b[31m%c \x1b[0m",keyboard_2[i]);
            }else{
                printf("%c ",keyboard_2[i]);
            }
            if(i == 9 || i == 19 || i == 29) printf("\n\t\t\t\t\t\t\t\t\t");
        }
    }
    if(debug) {
        printf("\x1b[6;1H\t\t\t\t\t\t\t\t\tIndice: %d ",k_index);
        printf("\x1b[5;1H\t\t\t\t\t\t\t\t\t%d",turn);
    }
    return false;
}
void printObject(Player player, int i){
    printf("\n");
    switch(player.inventory[i]){
        case 0:
            printf("-Empty           ");
            break;
        case 1:
            printf("-Double movement ");
            break;
        default:
            printf("-Undefined object");
            break;
    }
}
void printMap(char map[MAPSIZE][MAPSIZE], Player player_1, Player player_2, bool turn){
	int i,y;
    char letter;

    for(i=0;i<INVENTORY;i++){
        if(turn){
            if(i == 0){
                printf("\x1b[10;1H\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tHealth: %d",player_1.healt);
                printf("\x1b[7;1H--Player 1 inventory");
            }
            printObject(player_1,i);
        }
        else{
            if(i == 0){
                printf("\x1b[10;1H\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tHealth: %d",player_2.healt);
                printf("\x1b[7;1H--Player 2 inventory");
            }
            printObject(player_2,i);
        }
    }

    printf("\x1b[7;1H");
	for(i=0;i<MAPSIZE;i++){
        printf("\t\t\t\t\t\t\t");
		for(y=0;y<MAPSIZE;y++){
			if(map[i][y] == 'P') 
            {
                letter = player_1.letter;
                printf("\x1b[33m%c\x1b[0m", letter);
            }
            else if(map[i][y] == 'p') 
            {
                letter = player_2.letter;
                printf("\x1b[31m%c\x1b[0m", letter);
            }
            else if(map[i][y] == 'E') printf("\x1b[31m%c\x1b[0m", map[i][y]);
            else if(map[i][y] == '*') printf("\x1b[32m%c\x1b[0m", map[i][y]);
            else if(map[i][y] == 'B') printf("\x1b[31m%c\x1b[0m", map[i][y]);
            else if(map[i][y] == 'O' || map[i][y] == 'o') printf("\x1b[34m%c\x1b[0m", map[i][y]);
            else if(map[i][y] == 'C') printf("\x1b[35m%c\x1b[0m", map[i][y]);
            else if(map[i][y] == 'D' || map[i][y] == 'd') printf("\x1b[90m%c\x1b[0m", map[i][y]);
			else printf("%c", map[i][y]);
		}
		printf("\n");
	}

    
}
int searchPlayer(char map[MAPSIZE][MAPSIZE], bool x, bool player){ // mapa, coordenada x, jugador 1
	int i,y;
    char letter;

    if(player){
        letter = 'P';
    }
    else{
        letter = 'p';
    }
	for(i=0;i<MAPSIZE;i++){
		for(y=0;y<MAPSIZE;y++){
			if(map[i][y] == letter)
			{
				if(x)
				{
					return y;
				}
				else
				{
					return i;
				}
			}
		}
	}
	return -1;
}
bool gameProcessP1(char map[MAPSIZE][MAPSIZE]){
	int player_x;
	int player_y;

    player_x = searchPlayer(map,true,true);
    player_y = searchPlayer(map,false,true);
    printf("\x1b[8;1H\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t|Posicion actual|");
    printf("\x1b[9;1H\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tX: %d Y: %d",player_x,player_y);

    //hidKeysDown returns information about which buttons have been just pressed (and they weren't in the previous frame)
    u32 kDown = hidKeysDown(CONTROLLER_P1_AUTO);
    if(!shoot){
        if((kDown & KEY_DUP)){
            if(map[player_y-1][player_x] == ' '){
                map[player_y][player_x] = ' ';
                map[player_y-1][player_x] = 'P';
                return true;
            }
        }
        if(kDown & KEY_DDOWN){
            if(map[player_y+1][player_x] == ' '){
                map[player_y][player_x] = ' ';
                map[player_y+1][player_x] = 'P';
                return true;
            }
        }
        if(kDown & KEY_DLEFT){
            if(map[player_y][player_x-1] == ' '){
                map[player_y][player_x] = ' ';
                map[player_y][player_x-1] = 'P';
                return true;
            }
        }
        if(kDown & KEY_DRIGHT){
            if(map[player_y][player_x+1] == ' '){
                map[player_y][player_x] = ' ';
                map[player_y][player_x+1] = 'P';
                return true;
            }
        }
        if(kDown & KEY_L){
            printf("\x1b[11;1H\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t-Choose the direction-");
            shoot = true;
        }
    }
	else if(bullets[0] < maxBullets[0]){
        if((kDown & KEY_DUP)){
            if(map[player_y-1][player_x] == ' '){
                map[player_y-1][player_x] = '.';
                bullets[0]++;
                b_dir[bullets[0]-1] = 0;
                shoot = false;
                printf("\x1b[11;1H\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t                      ");
                return true;
            }
        }
        if(kDown & KEY_DDOWN){
            if(map[player_y+1][player_x] == ' '){
                map[player_y+1][player_x] = '.';
                bullets[0]++;
                b_dir[bullets[0]-1] = 1;
                shoot = false;
                printf("\x1b[11;1H\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t                      ");
                return true;
            }
        }
        if(kDown & KEY_DLEFT){
            if(map[player_y][player_x-1] == ' '){
                map[player_y][player_x-1] = '.';
                bullets[0]++;
                b_dir[bullets[0]-1] = 2;
                shoot = false;
                printf("\x1b[11;1H\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t                      ");
                return true;
            }
        }
        if(kDown & KEY_DRIGHT){
            if(map[player_y][player_x+1] == ' '){
                map[player_y][player_x+1] = '.';
                bullets[0]++;
                b_dir[bullets[0]-1] = 3;
                shoot = false;
                printf("\x1b[11;1H\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t                      ");
                return true;
            }
        }
    }
    else{
        shoot = false;
        printf("\x1b[11;1H\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t                      ");
    }

    return false;
}
bool gameProcessP2(char map[MAPSIZE][MAPSIZE]){
    int player_x;
    int player_y;

    player_x = searchPlayer(map,true,false);
    player_y = searchPlayer(map,false,false);

    printf("\x1b[8;1H\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t|Posicion actual|");
    printf("\x1b[9;1H\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tX: %d Y: %d",player_x,player_y);

    bool action = false;

    //hidKeysDown returns information about which buttons have been just pressed (and they weren't in the previous frame)
    u32 kDown = hidKeysDown(CONTROLLER_P1_AUTO);

    if((kDown & KEY_X)){
        if(map[player_y-1][player_x] == ' '){
            map[player_y][player_x] = ' ';
            map[player_y-1][player_x] = 'p';
            action = true;
            return action;
        }
    }
    if(kDown & KEY_B){
        if(map[player_y+1][player_x] == ' '){
            map[player_y][player_x] = ' ';
            map[player_y+1][player_x] = 'p';
            action = true;
            return action;
        }
    }
    if(kDown & KEY_Y){
        if(map[player_y][player_x-1] == ' '){
            map[player_y][player_x] = ' ';
            map[player_y][player_x-1] = 'p';
            action = true;
            return action;
        }
    }
    if(kDown & KEY_A){
        if(map[player_y][player_x+1] == ' '){
            map[player_y][player_x] = ' ';
            map[player_y][player_x+1] = 'p';
            action = true;
            return action;
        }
    }

    return action;
}

int main(int argc, char **argv)
{
	/*char keysNames[32][32] = {
        "KEY_A", "KEY_B", "KEY_X", "KEY_Y",
        "KEY_LSTICK", "KEY_RSTICK", "KEY_L", "KEY_R",
        "KEY_ZL", "KEY_ZR", "KEY_PLUS", "KEY_MINUS",
        "KEY_DLEFT", "KEY_DUP", "KEY_DRIGHT", "KEY_DDOWN",
        "KEY_LSTICK_LEFT", "KEY_LSTICK_UP", "KEY_LSTICK_RIGHT", "KEY_LSTICK_DOWN",
        "KEY_RSTICK_LEFT", "KEY_RSTICK_UP", "KEY_RSTICK_RIGHT", "KEY_RSTICK_DOWN",
        "KEY_SL", "KEY_SR", "KEY_TOUCH", "",
        "", "", "", ""
    };
    */
    char keyboard_1[KEYBOARD] = {'0','1','2','3','4','5','6','7','8','9',
                                'A','B','C','D','F','G','H','I','J','K',
                                'L','M','N','O','P','Q','R','S','T','U',
                                'V','W','X','Y','Z','$','/','@','%','&'};

    char keyboard_2[KEYBOARD] = {'0','1','2','3','4','5','6','7','8','9',
                                'a','b','c','d','f','g','h','i','j','k',
                                'l','m','n','o','p','q','r','s','t','u',
                                'v','w','x','y','z','#','=','*','?','!'};
    
    char map[MAPSIZE][MAPSIZE] = {
    {'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
    {'#',' ','o','#','C',' ',' ',' ',' ',' ','#',' ',' ','p','*','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
    {'#','M',' ','#',' ',' ',' ',' ',' ',' ','#',' ',' ',' ',' ','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
    {'#',' ',' ','#','o','#','#','#','#',' ',' ',' ',' ',' ',' ','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
    {'#',' ','#','#','#',' ',' ',' ','M',' ','#','#',' ',' ',' ','D','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
    {'#',' ','M',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','M',' ','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
    {'#',' ',' ',' ','#','#',' ','#','#',' ',' ','#',' ',' ',' ','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
    {'#',' ','M',' ',' ','#',' ','#',' ',' ',' ','#','M',' ',' ','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
    {'#',' ','#',' ',' ','#',' ',' ',' ','M',' ',' ',' ',' ',' ','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
    {'#',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
    {'#',' ','#',' ',' ',' ','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
    {'#',' ',' ',' ',' ',' ',' ',' ',' ','#',' ',' ',' ',' ','o','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
    {'#',' ','P','#',' ','M',' ','#','#','#',' ','#',' ',' ',' ','#',' ',' ',' ','#','#','#','#','#','#','#','#','#','#','#','#','#'},
    {'#',' ',' ','#',' ',' ',' ',' ',' ',' ',' ','#',' ',' ',' ','d',' ',' ','C','#','#','#','#','#','#','#','#','#','#','#','#','#'},
    {'#',' ',' ','#','o',' ',' ',' ','M',' ',' ','#','O',' ',' ','#',' ',' ',' ','#','#','#','#','#','#','#','#','#','#','#','#','#'},
    {'#','#','#','#','#','D','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
    {'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
    {'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
    {'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
    {'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
    {'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
    {'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
    {'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
    {'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
    {'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
    {'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
    {'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
    {'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
    {'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
    {'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
    {'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
    {'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'}
    };
    bool r_pressed = false;
    bool l_pressed = false;
    bool keyboard = false;
    bool start = false;
    bool game = false;
    bool turn = true;
    bool k_turn = true;
    int each_turn = 5;
    int i;

    Player player_1;
    Player player_2;

    player_1.letter = 'R';
    player_1.healt = 3;
    player_2.letter = 'P';
    player_2.healt = 3;

    for(i=0;i<INVENTORY;i++){
        player_1.inventory[i] = 1;
        player_2.inventory[i] = 0;
    }

    gfxInitDefault();
    consoleInit(NULL);

    printf("\x1b[1;1HPress L and R to start the game.");
    printf("\x1b[2;1HPress + to return Homebrew menu.");
    printf("\x1b[4;1H[Input] - Player 1");
    printf("\x1b[5;1H-↑,↓,→,← to control the character and keyboard [SL to switch caps]");
    printf("\x1b[6;1H-L to shoot and ↑,↓,→,← to select the direction");
    printf("\x1b[7;1H-ZR to open inventory and L to use an object");
    printf("\x1b[8;1H[Input] - Player 2");
    printf("\x1b[9;1H-X,B,A,Y to control the character and keyboard [SR to switch caps]");
    printf("\x1b[10;1H-R to shoot and X,B,A,Y to select the direction");
    printf("\x1b[11;1H-ZR to open inventory and R to use an object");

    // Main loop
    while(appletMainLoop())
    {
        //Scan all the inputs. This should be done once for each frame
        hidScanInput();

        u32 kDown = hidKeysDown(CONTROLLER_P1_AUTO);

        if (kDown & KEY_PLUS) break; // Volver al menú

        if(keyboard){
            if(!start){
                if(k_turn){
                    if(printKeyboard(k_turn, keyboard_1, keyboard_2)){
                        if(caps){
                            player_1.letter = keyboard_1[k_index];
                        }
                        else{
                            player_1.letter = keyboard_2[k_index];
                            
                        }
                        if(debug){
                            printf("\x1b[3;32HIndice: %d",k_index);
                            printf("\x1b[2;32HCaracter: %c",keyboard_1[k_index]);   
                        } 
                        caps = true;
                        k_index = 0;
                        k_turn = false;
                    }
                }
                else{
                    if(printKeyboard(k_turn, keyboard_1, keyboard_2)){
                        if(caps){
                            player_2.letter = keyboard_1[k_index];
                        }
                        else{
                            player_2.letter = keyboard_2[k_index];
                        }
                        caps = true;
                        k_index = 0;
                        start = true;
                    }
                }
            }
            else{
                keyboard = false;
                game = true; //Empezar partida
                consoleClear();
                printMap(map, player_1, player_2,turn); 
            }
        }

        if(!game && !keyboard){
            if(kDown & KEY_L){
                l_pressed = true;
            }
            if(kDown & KEY_R){
                r_pressed = true;
            }
            if(l_pressed && r_pressed){
                consoleClear();
                keyboard = true;
            }
        }
        if(start)
        {
            if(each_turn <= 0){
                if(turn){
                    if(gameProcessP1(map)){
                        each_turn = EACH_TURN;
                    }
                }
                else{
                    if(gameProcessP2(map)){
                        each_turn = EACH_TURN;
                    }
                }
                if(each_turn == EACH_TURN) 
                {
                    turn = !turn;
                    printMap(map,player_1,player_2,turn);
                }
                else
                {   
                    if(turn) printf("\x1b[7;1H\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t---Player 1---");
                    else printf("\x1b[7;1H\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t---Player 2---");
                }
            }
            else
            {
                each_turn--;
            }
        }

        gfxFlushBuffers();
        gfxSwapBuffers();
        gfxWaitForVsync();
    }

    gfxExit();
    return 0;
}
