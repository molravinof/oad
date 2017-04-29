#include <iostream>
#include<string>
using namespace std;


class cripto{
protected:
	string m_user;
	string m_msn;
	int m_key;
public:
	string minuscula="abcdefghijklmnopqrstuvwxyz";
	cripto():m_user(""),m_msn(""),m_key(0){}
	cripto(string usuario,string mensaje, int key):m_user(usuario),m_msn(mensaje),m_key(key){
		if(m_user=="emisor"){
			this->cesar();
		}
		else if(m_user=="receptor"){
			this->decesar();
		}
		else
			;	
	}
	
	int getKey(){   return this->m_key;}
	string getMsn(){   return this->m_msn;}
	string getUser(){	return this->m_user;}
	
	void setKey(int nk){    this->m_key=nk;}
	void setMsn(string msn){    this->m_msn=msn;}
	void cesar(){
		string xs;
		string ys=this->getMsn();
		for(string::iterator it=ys.begin();it!=ys.end();it++){
			if(!(minuscula.find(*it)==string::npos)){ //si esta en las minusculas
				int pos=minuscula.find(*it);
				pos+=this->getKey();
				if(pos>=minuscula.length()-1){ 
					pos%=minuscula.length(); //donde iba mod 26
					*it=minuscula[pos];
					xs+=*it;
				}
				else if(pos<0){
					pos%=minuscula.length();
					//pos+=minuscula.length();
					*it=minuscula[pos];
					xs+=*it;
				}
				else{
					*it=minuscula[pos];
					xs+=*it;
				}
			}
			else{
				xs+=*it;
			}
		}
		this->setMsn(xs);
	}
	
	void decesar(){
		string xs;
		string ys=this->getMsn();
		for(string::iterator it=ys.begin();it!=ys.end();it++){
			if(!(minuscula.find(*it)==string::npos)){ //si esta en las minusculas
				int pos=minuscula.find(*it);
				int tam=minuscula.length();
				pos-=this->getKey();
				if(pos>=(tam-1)){ 
					pos%=tam; //donde iba mod 26
					*it=minuscula[pos];
					xs+=*it;
				}
				else if(pos<0){
					pos%=tam;
					pos+=tam;
					*it=minuscula[pos];
					xs+=*it;
				}
				else{
					*it=minuscula[pos];
					xs+=*it;
				}
			}
			else{
				xs+=*it;
			}
		}
		this->setMsn(xs);
	}
};


int main(int argc, char *argv[]) {
	cripto e1("emisor","hola mundo",7);
	cout<<"mensaje enviado: "<<e1.getMsn()<<endl;
	string mensaje=e1.getMsn();
	int key=e1.getKey();
	
	cripto r1("receptor",mensaje,key);
	cout<<"mensaje recibido: "<<r1.getMsn();
	return 0;
}

