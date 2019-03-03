// Student Name: ilay köksal
// Date: 22.12.2016

//Solving sudoku 

#include <vector>
#include <iostream>

#include <cstdio>
#include <ctime>

using namespace std;

class coordinates{
public:
	int i;
	int j;
	coordinates(int i, int j){
		this->i = i;
		this->j = j;
	}
};

class area{
public:
	int area_goal_sum;
	int area_current_sum;
	int current_number;
	vector <coordinates> area_indexes;
	area(){
		area_current_sum = 0;
		current_number = 0;
	}
};

class puzzle{
public:
	int puzzle_grid[9][9];
	vector<area> areas;

	void puzzle_fill();
	//return true when there is empty location
	bool find_empty_location(int &i, int &j);
	//find corresponding area
	area* find_area(int i, int j);
	//return false when its ok
	bool used_in_box(int i, int j, int num);
	bool used_in_row(int i, int num);
	bool used_in_column(int j, int num);
	bool used_in_area(area area, int num);
	//return true when its ok  
	bool area_sum_control(area area, int num);
	//check all constraints
	bool is_safe(int i, int j, int num);
	bool solve();

};

void puzzle::puzzle_fill(){

	for (int i = 0; i < 9; i++){
		for (int j = 0; j < 9; j++){
			puzzle_grid[i][j] = 0;
		}
	}

	puzzle_grid[2][4] = 7;	
	puzzle_grid[4][2] = 6;	
	puzzle_grid[4][4] = 3;
	puzzle_grid[4][6] = 9;	
	puzzle_grid[6][4] = 2;
	

	//Area1
	area area1;
	area1.area_goal_sum = 19;
	coordinates coordinates_1_1(0, 0);
	coordinates coordinates_1_2(1, 0);
	coordinates coordinates_1_3(1, 1);
	coordinates coordinates_1_4(2, 0);
	area1.area_indexes.push_back(coordinates_1_1);
	area1.area_indexes.push_back(coordinates_1_2);
	area1.area_indexes.push_back(coordinates_1_3);
	area1.area_indexes.push_back(coordinates_1_4);
	areas.push_back(area1);

	//Area2
	area area2;
	area2.area_goal_sum = 17;
	coordinates coordinates_2_1(0, 1);
	coordinates coordinates_2_2(0, 2);
	coordinates coordinates_2_3(0, 3);
	coordinates coordinates_2_4(0, 4);
	area2.area_indexes.push_back(coordinates_2_1);
	area2.area_indexes.push_back(coordinates_2_2);
	area2.area_indexes.push_back(coordinates_2_3);
	area2.area_indexes.push_back(coordinates_2_4);
	areas.push_back(area2);

	//Area3
	area area3;
	area3.area_goal_sum = 21;
	coordinates coordinates_3_1(0, 5);
	coordinates coordinates_3_2(0, 6);
	coordinates coordinates_3_3(0, 7);
	coordinates coordinates_3_4(0, 8);
	area3.area_indexes.push_back(coordinates_3_1);
	area3.area_indexes.push_back(coordinates_3_2);
	area3.area_indexes.push_back(coordinates_3_3);
	area3.area_indexes.push_back(coordinates_3_4);
	areas.push_back(area3);

	//Area4
	area area4;
	area4.area_goal_sum = 21;
	coordinates coordinates_4_1(1, 2);
	coordinates coordinates_4_2(1, 3);
	coordinates coordinates_4_3(2, 2);
	area4.area_indexes.push_back(coordinates_4_1);
	area4.area_indexes.push_back(coordinates_4_2);
	area4.area_indexes.push_back(coordinates_4_3);
	areas.push_back(area4);

	//Area5
	area area5;
	area5.area_goal_sum = 11;
	coordinates coordinates_5_1(1, 4);
	coordinates coordinates_5_2(2, 3);
	coordinates coordinates_5_3(2, 4);
	area5.area_indexes.push_back(coordinates_5_1);
	area5.area_indexes.push_back(coordinates_5_2);
	area5.area_indexes.push_back(coordinates_5_3);
	areas.push_back(area5);

	//Area6
	area area6;
	area6.area_goal_sum = 16;
	coordinates coordinates_6_1(1, 5);
	coordinates coordinates_6_2(1, 6);
	area6.area_indexes.push_back(coordinates_6_1);
	area6.area_indexes.push_back(coordinates_6_2);
	areas.push_back(area6);

	//Area7
	area area7;
	area7.area_goal_sum = 5;
	coordinates coordinates_7_1(1, 7);
	coordinates coordinates_7_2(1, 8);
	area7.area_indexes.push_back(coordinates_7_1);
	area7.area_indexes.push_back(coordinates_7_2);
	areas.push_back(area7);

	//Area8
	area area8;
	area8.area_goal_sum = 12;
	coordinates coordinates_8_1(2, 1);
	coordinates coordinates_8_2(3, 0);
	coordinates coordinates_8_3(3, 1);
	area8.area_indexes.push_back(coordinates_8_1);
	area8.area_indexes.push_back(coordinates_8_2);
	area8.area_indexes.push_back(coordinates_8_3);
	areas.push_back(area8);

	//Area9
	area area9;
	area9.area_goal_sum = 11;
	coordinates coordinates_9_1(2, 5);
	coordinates coordinates_9_2(2, 6);
	coordinates coordinates_9_3(3, 5);
	area9.area_indexes.push_back(coordinates_9_1);
	area9.area_indexes.push_back(coordinates_9_2);
	area9.area_indexes.push_back(coordinates_9_3);
	areas.push_back(area9);

	//Area10
	area area10;
	area10.area_goal_sum = 17;
	coordinates coordinates_10_1(2, 7);
	coordinates coordinates_10_2(3, 6);
	coordinates coordinates_10_3(3, 7);
	area10.area_indexes.push_back(coordinates_10_1);
	area10.area_indexes.push_back(coordinates_10_2);
	area10.area_indexes.push_back(coordinates_10_3);
	areas.push_back(area10);

	//Area11
	area area11;
	area11.area_goal_sum = 21;
	coordinates coordinates_11_1(2, 8);
	coordinates coordinates_11_2(3, 8);
	coordinates coordinates_11_3(4, 7);
	coordinates coordinates_11_4(4, 8);
	area11.area_indexes.push_back(coordinates_11_1);
	area11.area_indexes.push_back(coordinates_11_2);
	area11.area_indexes.push_back(coordinates_11_3);
	area11.area_indexes.push_back(coordinates_11_4);
	areas.push_back(area11);

	//Area12
	area area12;
	area12.area_goal_sum = 13;
	coordinates coordinates_12_1(3, 2);
	coordinates coordinates_12_2(4, 2);
	area12.area_indexes.push_back(coordinates_12_1);
	area12.area_indexes.push_back(coordinates_12_2);
	areas.push_back(area12);

	//Area13
	area area13;
	area13.area_goal_sum = 11;
	coordinates coordinates_13_1(3, 3);
	coordinates coordinates_13_2(3, 4);
	area13.area_indexes.push_back(coordinates_13_1);
	area13.area_indexes.push_back(coordinates_13_2);
	areas.push_back(area13);

	//Area14
	area area14;
	area14.area_goal_sum = 18;
	coordinates coordinates_14_1(4, 0);
	coordinates coordinates_14_2(4, 1);
	coordinates coordinates_14_3(5, 0);
	coordinates coordinates_14_4(6, 0);
	area14.area_indexes.push_back(coordinates_14_1);
	area14.area_indexes.push_back(coordinates_14_2);
	area14.area_indexes.push_back(coordinates_14_3);
	area14.area_indexes.push_back(coordinates_14_4);
	areas.push_back(area14);

	//Area15
	area area15;
	area15.area_goal_sum = 8;
	coordinates coordinates_15_1(4, 3);
	coordinates coordinates_15_2(4, 4);
	coordinates coordinates_15_3(4, 5);
	area15.area_indexes.push_back(coordinates_15_1);
	area15.area_indexes.push_back(coordinates_15_2);
	area15.area_indexes.push_back(coordinates_15_3);
	areas.push_back(area15);

	//Area16
	area area16;
	area16.area_goal_sum = 15;
	coordinates coordinates_16_1(4, 6);
	coordinates coordinates_16_2(5, 6);
	area16.area_indexes.push_back(coordinates_16_1);
	area16.area_indexes.push_back(coordinates_16_2);
	areas.push_back(area16);

	//Area17 
	area area17;
	area17.area_goal_sum = 13;
	coordinates coordinates_17_1(5, 1);
	coordinates coordinates_17_2(5, 2);
	coordinates coordinates_17_3(6, 1);
	area17.area_indexes.push_back(coordinates_17_1);
	area17.area_indexes.push_back(coordinates_17_2);
	area17.area_indexes.push_back(coordinates_17_3);
	areas.push_back(area17);

	//Area18 
	area area18;
	area18.area_goal_sum = 16;
	coordinates coordinates_18_1(5, 3);
	coordinates coordinates_18_2(6, 2);
	coordinates coordinates_18_3(6, 3);
	area18.area_indexes.push_back(coordinates_18_1);
	area18.area_indexes.push_back(coordinates_18_2);
	area18.area_indexes.push_back(coordinates_18_3);
	areas.push_back(area18);

	//Area19
	area area19;
	area19.area_goal_sum = 17;
	coordinates coordinates_19_1(5, 4);
	coordinates coordinates_19_2(5, 5);
	area19.area_indexes.push_back(coordinates_19_1);
	area19.area_indexes.push_back(coordinates_19_2);
	areas.push_back(area19);
	
	//Area20
	area area20;
	area20.area_goal_sum = 13;
	coordinates coordinates_20_1(5, 7);
	coordinates coordinates_20_2(5, 8);
	coordinates coordinates_20_3(6, 7);
	area20.area_indexes.push_back(coordinates_20_1);
	area20.area_indexes.push_back(coordinates_20_2);
	area20.area_indexes.push_back(coordinates_20_3);
	areas.push_back(area20);

	//Area21
	area area21;
	area21.area_goal_sum = 8;
	coordinates coordinates_21_1(6, 4);
	coordinates coordinates_21_2(6, 5);
	coordinates coordinates_21_3(7, 4);
	area21.area_indexes.push_back(coordinates_21_1);
	area21.area_indexes.push_back(coordinates_21_2);
	area21.area_indexes.push_back(coordinates_21_3);
	areas.push_back(area21);

	//Area22
	area area22;
	area22.area_goal_sum = 16;
	coordinates coordinates_22_1(6, 6);
	coordinates coordinates_22_2(7, 5);
	coordinates coordinates_22_3(7, 6);
	area22.area_indexes.push_back(coordinates_22_1);
	area22.area_indexes.push_back(coordinates_22_2);
	area22.area_indexes.push_back(coordinates_22_3);
	areas.push_back(area22);

	//Area23
	area area23;
	area23.area_goal_sum = 22;
	coordinates coordinates_23_1(6, 8);
	coordinates coordinates_23_2(7, 7);
	coordinates coordinates_23_3(7, 8);
	coordinates coordinates_23_4(8, 8);
	area23.area_indexes.push_back(coordinates_23_1);
	area23.area_indexes.push_back(coordinates_23_2);
	area23.area_indexes.push_back(coordinates_23_3);
	area23.area_indexes.push_back(coordinates_23_4);
	areas.push_back(area23);

	//Area24
	area area24;
	area24.area_goal_sum = 17;
	coordinates coordinates_24_1(7, 0);
	coordinates coordinates_24_2(7, 1);
	area24.area_indexes.push_back(coordinates_24_1);
	area24.area_indexes.push_back(coordinates_24_2);
	areas.push_back(area24);

	//Area25
	area area25;
	area25.area_goal_sum = 8;
	coordinates coordinates_25_1(7, 2);
	coordinates coordinates_25_2(7, 3);
	area25.area_indexes.push_back(coordinates_25_1);
	area25.area_indexes.push_back(coordinates_25_2);
	areas.push_back(area25);

	//Area26
	area area26;
	area26.area_goal_sum = 21;
	coordinates coordinates_26_1(8, 0);
	coordinates coordinates_26_2(8, 1);
	coordinates coordinates_26_3(8, 2);
	coordinates coordinates_26_4(8, 3);
	area26.area_indexes.push_back(coordinates_26_1);
	area26.area_indexes.push_back(coordinates_26_2);
	area26.area_indexes.push_back(coordinates_26_3);
	area26.area_indexes.push_back(coordinates_26_4);
	areas.push_back(area26);

	//Area27
	area area27;
	area27.area_goal_sum = 18;
	coordinates coordinates_27_1(8, 4);
	coordinates coordinates_27_2(8, 5);
	coordinates coordinates_27_3(8, 6);
	coordinates coordinates_27_4(8, 7);
	area27.area_indexes.push_back(coordinates_27_1);
	area27.area_indexes.push_back(coordinates_27_2);
	area27.area_indexes.push_back(coordinates_27_3);
	area27.area_indexes.push_back(coordinates_27_4);
	areas.push_back(area27);

	find_area(2, 4)->area_current_sum = 7;
	find_area(2, 4)->current_number = 1;
	find_area(4, 2)->area_current_sum = 6;
	find_area(4, 2)->current_number = 1;
	find_area(4, 4)->area_current_sum = 3;
	find_area(4, 4)->current_number = 1;
	find_area(4, 6)->area_current_sum = 9;
	find_area(4, 6)->current_number = 1;
	find_area(6, 4)->area_current_sum = 2;
	find_area(6, 4)->current_number = 1;
	
}

bool puzzle::find_empty_location(int &i, int &j){
	
	for (i = 0; i < 9; i++){
		for (j = 0; j < 9; j++){
			if (puzzle_grid[i][j] == 0)
				return true;
		}
	}
	return false;
}

area *puzzle::find_area(int i, int j){
	for (int x = 0; x < areas.size(); x++){
		for (int y = 0; y < areas[x].area_indexes.size(); y++){
			if (areas[x].area_indexes[y].i == i && areas[x].area_indexes[y].j == j)
				return &areas[x];
			else
				continue;
		}
	}
};

bool puzzle::used_in_box(int box_i, int box_j, int num){	
	
	if (box_i < 3){
		if (box_j < 3){	box_i = 0;box_j = 0;}
		else if (box_j < 6){box_i = 0;box_j = 3;}
		else{box_i = 0;	box_j = 6;}
	}
	else if (box_i < 6){
		if (box_j < 3){box_i = 3;box_j = 0;}
		else if (box_j < 6){box_i = 3;box_j = 3;}
		else{box_i = 3;	box_j = 6;}
	}
	else {
		if (box_j < 3){	box_i = 6;box_j = 0;}
		else if (box_j < 6){box_i = 6;box_j = 3;}
		else{box_i = 6;	box_j = 6;}
	}
	
	for (int i = box_i; i < (box_i+3); i++){
		for (int j = box_j; j < (box_j+3); j++){
			if (puzzle_grid[i][j] == num)
				return true;
		}
	}
	return false;
};

bool puzzle::used_in_row(int i, int num){
	for (int j = 0; j < 9; j++){
		if (puzzle_grid[i][j] == num)
			return true;
	}
	return false;
};

bool puzzle::used_in_column(int j, int num){
	for (int i = 0; i < 9; i++){
		if (puzzle_grid[i][j] == num)
			return true;
	}
	return false;
};

bool puzzle::used_in_area(area area, int num){
	// check each square in area
	for (int x = 0; x < area.area_indexes.size(); x++){
		if (puzzle_grid[area.area_indexes[x].i][area.area_indexes[x].j] == num)
			return true;
	}
	return false;
};

bool puzzle::area_sum_control(area area, int num){
	if ((area.current_number + 1 == area.area_indexes.size()) && area.area_current_sum + num != area.area_goal_sum)
		return false;
	else if ((area.area_indexes.size()>=3) && (area.current_number + 2 == area.area_indexes.size()) && area.area_goal_sum - area.area_current_sum - num > 9 )
		return false;
	else if ((area.area_indexes.size() >= 3) && (area.current_number + 2 == area.area_indexes.size()) && used_in_area(area, area.area_goal_sum - area.area_current_sum - num))
		return false;
	else if ((area.area_indexes.size()==4) && (area.current_number + 3 == area.area_indexes.size()) && area.area_goal_sum - area.area_current_sum - num > 18)
		return false;
	else if (area.area_current_sum + num > area.area_goal_sum)
		return false;
	else
		return true;
};

bool puzzle::is_safe(int i, int j, int num){	
	return (!used_in_box(i, j, num) &&
		!used_in_row(i, num) &&
		!used_in_column(j, num) &&
		!used_in_area(*find_area(i, j), num) && 
		area_sum_control(*find_area(i, j), num));
}

bool puzzle::solve(){

	int row, column;
	//puzzle solved
	if (!find_empty_location(row,column))
		return true;

	for (int number = 1; number <= 9; number++)
	{
		if (is_safe(row, column, number)){
			puzzle_grid[row][column] = number;
			find_area(row, column)->area_current_sum += number;
			find_area(row, column)->current_number = find_area(row, column)->current_number+1;
			//cout << number <<" added to " << row << ", " << column << endl;
 			bool x = solve();
			if (x)
				return true;			

			puzzle_grid[row][column] = 0;
			//cout << number << " deleted from " << row << ", " << column << endl;
			find_area(row, column)->area_current_sum -= number;
			find_area(row, column)->current_number = find_area(row, column)->current_number-1;
		}
	}
	return false;
}

int main(){

	puzzle Sudoku;
	Sudoku.puzzle_fill();
	clock_t start;
	start = clock();
	double duration;
	if (Sudoku.solve()){
		cout << "solved" << endl;
		duration = (clock() - start) / (double)CLOCKS_PER_SEC;
		for (int i = 0; i < 9; i++){
			for (int j = 0; j < 9; j++){
				cout << Sudoku.puzzle_grid[i][j] << " ";
			}
			cout << endl;
		}
		cout <<" duration:" <<duration << endl;
	}
	else
		cout << "nope" << endl;
	getchar();
}
