
// Red Team
spyOne = new Spy(false);

twoOne = new Normal_Piece(2, false);
twoTwo = new Normal_Piece(2, false);
twoThree = new Normal_Piece(2, false);
twoFour = new Normal_Piece(2, false);
twoFive = new Normal_Piece(2, false);
twoSix = new Normal_Piece(2, false);
twoSeven = new Normal_Piece(2, false);
twoEight = new Normal_Piece(2, false);

threeOne = new Three(false);
threeTwo = new Three(false);
threeThree = new Three(false);
threeFour = new Three(false);
threeFive = new Three(false);

fourOne = new Normal_Piece(4, false);
fourTwo = new Normal_Piece(4, false);
fourThree = new Normal_Piece(4, false);
fourFour = new Normal_Piece(4, false);

fiveOne = new Normal_Piece(5, false);
fiveTwo = new Normal_Piece(5, false);
fiveThree = new Normal_Piece(5, false);
fiveFour = new Normal_Piece(5, false);

sixOne = new Normal_Piece(6, false);
sixTwo = new Normal_Piece(6, false);
sixThree = new Normal_Piece(6, false);
sixFour = new Normal_Piece(6, false);

sevenOne = new Normal_Piece(7, false);
sevenTwo = new Normal_Piece(7, false);
sevenThree = new Normal_Piece(7, false);

eightOne = new Normal_Piece(8, false);
eightTwo = new Normal_Piece(8, false);

nineOne = new Normal_Piece(9, false);

tenOne = new Normal_Piece(9, false)

bombOne = new Normal_Piece(99, false);
bombTwo = new Normal_Piece(99, false);
bombThree = new Normal_Piece(99, false);
bombFour = new Normal_Piece(99, false);
bombFive = new Normal_Piece(99, false);
bombSix = new Normal_Piece(99, false);

flag = new Normal_Piece(-1, false);

// Blue Team
spyOne = new Spy(true);

twoOne = new Normal_Piece(2, true);
twoTwo = new Normal_Piece(2, true);
twoThree = new Normal_Piece(2, true);
twoFour = new Normal_Piece(2, true);
twoFive = new Normal_Piece(2, true);
twoSix = new Normal_Piece(2, true);
twoSeven = new Normal_Piece(2, true);
twoEight = new Normal_Piece(2, true);

threeOne = new Three(true);
threeTwo = new Three(true);
threeThree = new Three(true);
threeFour = new Three(true);
threeFive = new Three(true);

fourOne = new Normal_Piece(4,true);
fourTwo = new Normal_Piece(4, true)
fourThree = new Normal_Piece(4, true)
fourFour = new Normal_Piece(4, true);

fiveOne = new Normal_Piece(5, true);
fiveTwo = new Normal_Piece(5, true);
fiveThree = new Normal_Piece(5, true);
fiveFour = new Normal_Piece(5, true);

sixOne = new Normal_Piece(6, true);
sixTwo = new Normal_Piece(6, true);
sixThree = new Normal_Piece(6, true);
sixFour = new Normal_Piece(6, true);

sevenOne = new Normal_Piece(7, true);
sevenTwo = new Normal_Piece(7, true);
sevenThree = new Normal_Piece(7, true);

eightOne = new Normal_Piece(8, true);
eightTwo = new Normal_Piece(8, true);

nineOne = new Normal_Piece(9, true);

tenOne = new Normal_Piece(9, true)

bombOne = new Normal_Piece(99, true);
bombTwo = new Normal_Piece(99, true);
bombThree = new Normal_Piece(99, true);
bombFour = new Normal_Piece(99, true);
bombFive = new Normal_Piece(99, true);
bombSix = new Normal_Piece(99, true);

flag = new Normal_Piece(-1, true);

//Save Function
ofstream outfile("saveFile.txt");
if (outfile) {
	for (i = 0, i = array.size(), i++) {
		outfile << array[i] << endl;
	}
}
outfile.close();

//Load Function

ifstream infile("saveFile.txt");
int counter = 0;
	while (infile) {
		array[counter] = in.getline(infile, temp);
		counter += 1;
	}

