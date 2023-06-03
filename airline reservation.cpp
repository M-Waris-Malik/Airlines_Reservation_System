#include <iostream>
#include <vector>
using namespace std;

class Flight{
	private:
		string flightNo, departure, destination;
		int capacity, reserved;
	public:
		Flight(string flight, string dep, string des, int cap){
			flightNo= flight;
			departure = dep; 
			destination = des; 
			capacity = cap;
			reserved =  0; 
		}
bool	reservation(){
	if(reserved < capacity){
		reserved++;
		return true;
	}
	return false;
	}
	
	friend class ReservationSystem;
};

class ReservationSystem{
	public:
		vector<Flight> ve;
		
	add(string flight ,string dep, string des, int cap){
		Flight newflight(flight, dep, des, cap);
		ve.push_back(newflight);
	}
	
	reserveSeat(){
		cout<<"<<<<< Available Flights >>>>>"<<endl<<endl;
		for(int i=0; i<ve.size(); i++){
		cout<<"Flight: "<<ve[i].flightNo<<endl;
		cout<<"Departure: "<<ve[i].departure<<endl;
		cout<<"Destination: "<<ve[i].destination<<endl;
		cout<<"Total Seats: "<<ve[i].capacity<<endl<<endl;
		}
		
		string fn;
		cout<<"Enter Flight No: "; cin>>fn;
		for(int i=0; i<ve.size(); i++){
			if(fn==ve[i].flightNo){
		if(ve[i].reservation()){
		cout<<"You have reserved seat on flight: "<<ve[i].flightNo<<endl;
		}//nested if
		else{
			cout<<"Sorry! Seats not available:"<<endl<<endl;
		}
			}//if
		}//for
	}//function
};

int main(){
	ReservationSystem rs;
	rs.add("F101", "UAE", "USA", 2);
	rs.add("F202", "UK", "Canada", 150);
	rs.add("F303", "UK", "UAE", 100);
	cout<<"<<<<< ABC Airline >>>>>"<<endl<<endl;
	while(true){
		int choice;
	cout<<"Enter 1 for reserve seat "<<endl;
	cout<<"Enter 0 for exit"<<endl;
	cout<<"Enter choice: "; cin>>choice;
	if(choice==1){
	system("cls");
	rs.reserveSeat();
}
else if(choice==0){
	exit(0);
}
	}
}
