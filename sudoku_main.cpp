#include<bits/stdc++.h>
#include<windows.h>
#include"sudoku.hpp"
#include"menuChooser.h"
using namespace std;
menu::MenuTable titleChooser(2,"Heny's sudoku game",{
	"play general sudoku",
	"play %-sudoku",
	"help",
	"quit"
});
menu::MenuTable generateChooser(2,"initializing the sudoku",{
	"choose from presets",
	"generate a new sudoku",
	"back to title"
});
menu::MenuTable difficultyChooser(4,"difficulty",{
	"easy",
	"normal",
	"hard",
	"custom"
});
vector<string> sudoku_preset={
	".8.........9.8..457.6.1......4..6.......2...........91.714...5...8.5.7..2..89...6",
	"942...5....3......15..4........5.....1..739..794..1...5.9.841.7.3.....5.....324..",
	"..2......5..8.1..2..8.751..9..3.6..765.........1......1....7.9......3....29.5...8",
	"3....19.2..7..8..5....3.4....2.......4.1.......3..5....9.5.48.1......74..1.8..5.9",
	"9..6....7..3..9......21...5..8.9.5...7...398.........62.61.7......36....5....2..1",
	"......267.........96..21.3......98.4.......79...6..31.18..9......4.17.9.2....4...",
	"2........5.697.......1.....7....96....3.1..5.8...32..9....6.9.3....957.2...8....5",
	"....3...6.5....32.3.2.918.......8..1.........871......29...6..7....87.3...75.9...",
	".8......1...4...6.576..........7.....9....3.6...84.7....5.6...........1841.7...93",
	"32...6.....5....9..7....3..5.2...6.769..2...........4..6....7..7.9.325.1......234",
	".54.1..37......5..3.7..46.1........66.1....5..2.8.......5.3....7.62...14...146...",
	"4.9.....68.......4.7...3...9.....41361...7.89.4.8.....3...2.7...6.....9...8....62",
	"....567...3..7...5.....1.....6.1.27.1...2.....2..4.3....756..1...5..9.6......4..3",
	".247.....1...3.29.....5......8....4..12.78...3..59....25..1........8..59.39......"
};
vector<string> psudoku_preset={
	".......9....23.6...3.7....5.....4........69........8...82..9....9.....2..1.......",
	"...67...........8..........15..342....3.57.6..2...............8...9.6........2...",
	"............9........41..2.7..2.5....48..7.....6..47.....8......7...........52...",
	"..3...1..95..7....8...........3.6.1.....9.............1.......73..6..2...4....9..",
	".9.........7.58.........972...5..29..........7.......8.5...3.......6.1..8.6....2.",
	"...18..6...1.......62.7...9.....8...3...2.............5....7....4..3...1.........",
	"2..6....1....5.......9......6.8..1...27...58.......4................6...5.9......",
	".....4.....1........29..6....3....7............4.........16.....47.....9.58....2.",
	".......4...3..5..1...8........1........7..6.98..6.95.3......3..........4.........",
	"......89....5......9..4.6.7......9............26.....1............8.24...8....76.",
	"....7.....978....62.6.....9....1..7..58....2.......4.....................2......8",
	// ".3....5..8.......3714...892...4............3...9...2...9.....8.2.........5.......",
	".....3.5..2..8.......6.9.13...1.6....1.....2....9.8...28.7.5.......1..9..9.3.....",
	"9....3.58.2..8.....7.6.9213..91.6...81.....29...9.81..2847.5.6.....1..9.19.3....2"
};
int main(){
	while(1){
		int chs=titleChooser.choose();
		if(chs==4) break;
		if(chs==3){
			cout<<"When playing Sudoku, \npress the arrow keys to move the cursor, \npress the keys 1 to 9 to fill in the blanks, \nand press the enter key to exit.";
			continue;
		}
		SUDOKU *baseptr;
		vector<string> *preset;
		menu::MenuTable *sudoku_chooser;
		if(chs==1){
			baseptr=new sudoku;
			preset=&sudoku_preset;
			sudoku_chooser=new menu::MenuTable(1,"choose a sudoku",sudoku_preset);
		}
		if(chs==2){
			baseptr=new psudoku;
			preset=&psudoku_preset;
			sudoku_chooser=new menu::MenuTable(1,"choose a sudoku",psudoku_preset);
		}
		system("cls");
		int genchs=generateChooser.choose();
		if(genchs==3){
			system("cls");
			continue;
		}
		if(genchs==1){
			int prechs=sudoku_chooser->choose();
			baseptr->readString((*preset)[prechs-1].c_str());
			cout<<"solving sudoku ...\n";
			baseptr->solve();
			cout<<"sudoku solved in "<<baseptr->rtime()<<" ms\n";
		}
		if(genchs==2){
			system("cls");
			int difchs=difficultyChooser.choose();
			int del;
			if(difchs==4){
				cout<<"Please enter the number of digits you want to remove(1~80):";
				while(1){
					cin>>del;
					if(del>=1&&del<=80) break;
					cout<<"please enter a number from 1 to 80:";
				}
			}else{
				del=20*difchs;
			}

			cout<<"generating sudoku ...\n";
			baseptr->generate(del);
			cout<<"sudoku generated in "<<baseptr->rtime()<<" ms\n";
		}
		Sleep(1000);
		baseptr->play();
		system("cls");
	}
	cout<<"Thank you for playing!";
	Sleep(1000);
}