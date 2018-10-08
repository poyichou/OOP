#include<iostream>
#include<string>
#include<cstdio>
using namespace std;
class People
{
	protected:
		float HP;
		float Shield_HP;
	public:
		People()
		{
			HP =100;
			Shield_HP = 0;
		}
		float getHP()
		{
			return HP;
		}
		float getshield()
		{
			return Shield_HP;
		}
		void spell()
		{
			Shield_HP = 100;
		}
		void setshield(int n)
		{
			Shield_HP -= n;
		}
		void setHP(int n){
			HP -= n;
		}
};
class Swordsman : virtual public People
{
	protected:
		string weapon;
		float attvol;
	public:
		float sattack()
		{
			return attvol;
		}
		void sets(int n)
		{
			if(n == 0){
				weapon = "sword";
				attvol = 10;
			}else if(n == 1){
				weapon = "M60";
				attvol = 20;
			}else if(n == 2){
				weapon = "Excalibur";
				attvol = 100;
			}
		}
};
class Wizard : virtual public People
{
	protected:
		string wand;
		float attmul;
		float Spell_magic;
	public:
		float wattack()
		{
			return Spell_magic * attmul;
		}
//		void setspellmagic(int n)
//		{
//			if(n == 0){
//				Spell_magic = 50;
//			}else if(n == 1){
//				Spell_magic = 100;
//			}
//		}
		void setw(int n)
		{
			if(n == 0){
				wand = "Wood wand";
				attmul = 1;
			}else if(n == 1){
				wand = "Silver wand";
				attmul = 1.2;
			}else if(n == 2){
				wand = "Gold wand";
				attmul = 2;
			}
		}
};
class Magika : public Swordsman, public Wizard
{
	int mode;
	public:
		float attack()
		{
			if(mode == 0){
				return attvol;
			}else if(mode == 1){
				return attmul;
			}
		}
		
		void attshield(int n)
		{
			Shield_HP -= n;
		}
		Magika() : People(){}
		void setatt(int n)
		{
			mode = n;
		}
};
class Boss
{
	protected:
		float HP;
		float damage;
	public:
		Boss()
		{
			HP = 500;
			damage = 50;
		}
		void setHP(int n)
		{
			HP -= n;
		}
		float getHP()
		{
			return HP;
		}
};
int main(void)
{
	Magika hero;
	Boss boss;
	int round = 1;
	int command1, command2;
	cout << "Please choose weapon for hero. [0]:sword,[1]:M60,[2]:Excalibur >>" << endl;
	cin >> command1;
	cout << "Please choose wand for hero. [0]:Wood wand,[1]:Silver wand,[2]:Gold wand >>" << endl;
	cin >> command2;
	hero.sets(command1);
	hero.setw(command2);
	while(1)
	{
		cout <<"hero.sattack()= "<< hero.sattack() << endl;
		cout << endl << "Round " << round++ << endl;
		cout << " Boss HP (" << boss.getHP() << "/500): ";
		for(int i = 0 ; i < boss.getHP() / 10 ; i++){
			cout << "| ";
		}cout << endl;
		cout << " Hero HP (" << hero.getHP() << "/100): ";
		for(int i = 0 ; i < hero.getHP() / 10 ; i++){
			cout << "| ";
		}cout << endl;
		if(hero.getshield() > 0){
			cout << " Shield HP (" << hero.getshield() << "/100): ";
			for(int i = 0 ; i < hero.getshield() / 10 ; i++){
				cout << "| ";
			}cout << endl;
		}
		cout << "Boss Attack!!" << endl;
		cout << "Select attack or magic for Hero. [0]:attack,[1]:magic >>";
		cin >> command1;
		if(command1 == 0){
			
			
			
			
			hero.setatt(command1);
			boss.setHP(hero.attack());
			if(hero.getshield() > 0){
				cout << "Hero got 40 Damage(shield)" << endl << "Boss got " << hero.attack() <<" Damage" << endl << endl;
				hero.setshield(40);
				boss.setHP(hero.attack());
			}else if(hero.getshield() <= 0){
				cout << "Hero got 50 Damage" << endl << "Boss got " << hero.attack() <<" Damage" << endl << endl;
				hero.setHP(50);
				boss.setHP(hero.attack());
			}
			
			
			
			
			
		}else if(command1 == 1){
			hero.setatt(command1);
			cout << "Select skill for Hero. [0]:shield,[1]:fire,[2]:water,[3]:thunder >>";
			cin >> command2;
			if(command2 == 0){
				cout << "Hero got 40 Damage(shield)" << endl << "Boss got 0 Damage" << endl << endl;
				hero.spell();
				hero.setshield(40);
			}else if(command2 == 1 || command2 == 2 || command2 == 3){
				if(hero.getshield() > 0){
					cout << "Hero got 40 Damage(shield)" << endl << "Boss got" << 50 * hero.attack() <<" Damage" << endl << endl;
					hero.setshield(40);
					boss.setHP(50 * hero.attack());
				}else if(hero.getshield() <= 0){
					cout << "Hero got 50 Damage" << endl << "Boss got" << 50 * hero.attack() <<" Damage" << endl << endl;
					hero.setHP(50);
					boss.setHP(50 * hero.attack());
				}
			}else if(command2 == 13112){
				if(hero.getshield() > 0){
					cout << "Hero got 40 Damage(shield)" << endl << "Boss got " << 100 * hero.attack() <<" Damage" << endl << endl;
					hero.setshield(40);
					boss.setHP(100 * hero.attack());
				}else if(hero.getshield() <= 0){
					cout << "Hero got 50 Damage" << endl << "Boss got " << 100 * hero.attack() <<" Damage" << endl << endl;
					hero.setHP(50);
					boss.setHP(100 * hero.attack());
				}
			}
		}
		if(hero.getHP() <= 0){
			cout << "Game over!!!" << endl;
			break;
		}else if(boss.getHP() <= 0){
			cout <<" You Win!!!" << endl;
			break;
		}
		
	}
}
