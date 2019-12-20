#include<iostream>
#include<cstdlib>
#include<fstream>
using namespace std;

class Chicken {
	private:
		int age;
		int egg;
	public:
		Chicken(){
			age = 0;
			egg = 0;

		}
	void layegg(){
		egg +=1;
	}
	void Age(){age+=1;}
	float getAge(){
		return age;
	}
	int getEggs(){
		return egg;
	}
	void Reset(){
		egg = 0;
		age = 0;
	}

};

int main(){
	ifstream input_file;
	input_file.open("day_lengths");
	char cha;
	float lmax, lmin,hours, min;
	int n, day, tot,times;
	bool laying = false;
	cout<<"enter the number of chicken you want to raise: "<< endl;
	cin>>n;
	cout<<"enter how many years you want to keep them for: "<<endl;
	cin >> times;
	Chicken flock[n];
	int year_days[365];

	for (int i =0; i<n;i++){
		flock[i] = Chicken();
	}
	int count =0;
	

	while(!input_file.eof()){
		input_file >> hours >> cha >> min;
		hours = hours+ (min/60);
		year_days[count] = hours;
		count +=1;
	}	
		
	
//with no sup light and no culling
cout << "No sup light and no culling"<< endl;

		for (int t=0; t<365; t++){
			if((t-30)<0){
				for(int i =0; i<t; i++){
					if (year_days[i]> lmax){
						lmax = year_days[i];
					}
					if(year_days[i]<lmin){
						lmin = year_days[i];
					}
				}
			}
			else if ((t-30)>0){
				for (int i =(t-30); i<t;i++){
					if(year_days[i]>lmax){
						lmax = year_days[i];
					}
					if(year_days[i]<lmin){
						lmin = year_days[i];
					}
				}
			}
		
		day +=1;
		
			

		if ( year_days[t]< lmax - 0.75){
		laying = false;
		for(int s=0; s<n ;s++){
			flock[s].Age();
		}
		}
		else if(year_days[t] >lmin + 0.5){
			for(int s = 0; s < n; s++){
				if (flock[s].getAge()<=120){
				       flock[s].Age();
				       //cout<<flock[s].getEggs()<< endl;
					
				       
				}
		 		else if( 120<flock[s].getAge()<= 1095){
					int chance = (rand()% 100);
					flock[s].Age();
					if (chance <=80){
						flock[s].layegg();
						//cout<<"chicken "<<s << "layed an egg" << endl;
					}
				}
				else if(1095<flock[s].getAge()<=1825){
					int chance = (rand()%100);
					flock[s].Age();
					if (chance <=50){
						flock[s].layegg();
					}
				}
				else if(1825<flock[s].getAge()){
					int chance = (rand()%100);
					flock[s].Age();
					if (chance <=5){
						flock[s].layegg();
					}
				}
			}
		}
	
	}
	
	for(int i = 0; i<n; i++){
		cout << "chicken "<< i <<" layed "<<flock[i].getEggs() <<"eggs"<< endl;
		cout << "chicken "<<i << "is " << ((flock[i].getAge())/365)<< "years old" <<endl;  
		tot += flock[i].getEggs();
	}
	
		cout<< "the total number of eggs is "<< tot<<endl;	
		
		cout<<hours<< "  " <<min<<endl;

	day = 0;
	for (int i=0; i<n; i++){
		flock[i].Reset();
	}
	lmax=lmin=0;
	tot = 0;
//with sup light and no culling
cout << "with sup light and no culling "<<endl;
	for (int l=0; l< times; l++){
		for (int t=0; t<365; t++){
			if((t-30)<0){
				for(int i =0; i<t; i++){
					if (year_days[i]> lmax){
						lmax = year_days[i];
					}
					if(year_days[i]<lmin){
						lmin = year_days[i];
					}
				}
			}
			else if ((t-30)>0){
				for (int i =(t-30); i<t;i++){
					if(year_days[i]>lmax){
						lmax = year_days[i];
					}
					if(year_days[i]<lmin){
						lmin = year_days[i];
					}
				}
			}
		
		day +=1;
		
			
			for(int s = 0; s < n; s++){
				if (flock[s].getAge()<=120){
				       flock[s].Age();
				       //cout<<flock[s].getEggs()<< endl;
					
				       
				}
		 		else if( 120<flock[s].getAge()<= 1095){
					int chance = (rand()% 100);
					flock[s].Age();
					if (chance <=80){
						flock[s].layegg();
						//cout<<"chicken "<<s << "layed an egg" << endl;
					}
				}
				else if(1095<flock[s].getAge()<=1825){
					int chance = (rand()%100);
					flock[s].Age();
					if (chance <=50){
						flock[s].layegg();
					}
				}
				else if(1825<flock[s].getAge()){
					int chance = (rand()%100);
					flock[s].Age();
					if (chance <=5){
						flock[s].layegg();
					}
				}
			}
		}
	
	
	for(int i = 0; i<n; i++){
		cout << "chicken "<< i <<" layed "<<flock[i].getEggs() <<"eggs"<< endl;
		cout << "chicken "<<i << "is " << ((flock[i].getAge())/365)<< "years old" <<endl;  
		tot += flock[i].getEggs();
	}
	}
	cout<< "the total number of eggs is "<< tot<<endl;


	
cout << " 		report"<< endl<<" the best method is suplemental light without culling, followed by suplemental light and culling then no suplemental light and no calling and the worst is no suplemental light and culling."<<endl;
}

