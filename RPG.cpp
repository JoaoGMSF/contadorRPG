#include <iostream>
#include <string>
using namespace std;

typedef struct celula{
  int dano_causado=0;
  int dano_recebido=0;
  int acertos_criticos=0;
  int erros_critícos=0;
  int qtd_kills=0;
  string nome_personagem;
  celula *next=NULL;
}personagem;

void add_dmgcsd(personagem *ponteiro){
  personagem *ponteiro_extra = new personagem();
  ponteiro_extra = ponteiro;
  string personagem;
  int dano;
  cout<<"Quem deu o dano? ";
  cin>>personagem;
  cout<<"deu quanto de dano? ";
  cin>>dano;
  while (personagem!=ponteiro_extra->nome_personagem)
  {
    ponteiro_extra=ponteiro_extra->next;
    if(ponteiro_extra->nome_personagem==personagem){
      ponteiro_extra->dano_causado+=dano;
    }
    else if(personagem!=ponteiro_extra->nome_personagem && ponteiro_extra->next==NULL){
      cout<<"Tem certeza que digitou o nome certo? se não, tente novamente ";
      cin>> personagem;
      ponteiro_extra=ponteiro;
    }
  }
}

void add_dmgrcv(personagem *ponteiro){
  personagem *ponteiro_extra = new personagem();
  ponteiro_extra = ponteiro;
  string personagem;
  int dano;
  cout<<"Quem levou o dano? ";
  cin>>personagem;
  cout<<"levou quanto de dano? ";
  cin>>dano;
  while (personagem!=ponteiro_extra->nome_personagem)
  {
    ponteiro_extra=ponteiro_extra->next;
    if(ponteiro_extra->nome_personagem==personagem){
      ponteiro_extra->dano_recebido+=dano;
    }
    else if(personagem!=ponteiro_extra->nome_personagem && ponteiro_extra->next==NULL){
      cout<<"Tem certeza que digitou o nome certo? se não, tente novamente ";
      cin>> personagem;
      ponteiro_extra=ponteiro;
    }
  }
}

void add_acertocrit(personagem *ponteiro){
  personagem *ponteiro_extra = new personagem();
  ponteiro_extra = ponteiro;
  string personagem;
  cout<<"Quem deu o acerto critíco? ";
  cin>>personagem;
  while (personagem!=ponteiro_extra->nome_personagem)
  {
    ponteiro_extra=ponteiro_extra->next;
    if(ponteiro_extra->nome_personagem==personagem){
      ponteiro_extra->acertos_criticos+=1;
    }
    else if(personagem!=ponteiro_extra->nome_personagem && ponteiro_extra->next==NULL){
      cout<<"Tem certeza que digitou o nome certo? se não, tente novamente ";
      cin>> personagem;
      ponteiro_extra=ponteiro;
    }
  }
}

void add_errocrit(personagem *ponteiro){
  personagem *ponteiro_extra = new personagem();
  ponteiro_extra = ponteiro;
  string personagem;
  cout<<"Quem deu o erro critíco? ";
  cin>>personagem;
  while (personagem!=ponteiro_extra->nome_personagem)
  {
    ponteiro_extra=ponteiro_extra->next;
    if(ponteiro_extra->nome_personagem==personagem){
      ponteiro_extra->erros_critícos+=1;
    }
    else if(personagem!=ponteiro_extra->nome_personagem && ponteiro_extra->next==NULL){
      cout<<"Tem certeza que digitou o nome certo? se não, tente novamente ";
      cin>> personagem;
      ponteiro_extra=ponteiro;
    }
  }
}

void add_kill(personagem *ponteiro){
  personagem *ponteiro_extra = new personagem();
  ponteiro_extra = ponteiro;
  string personagem;
  int kills;
  cout<<"Quem matou alguem? ";
  cin>>personagem;
  cout<<"Matou quantos? ";
  cin>> kills;
  while (personagem!=ponteiro_extra->nome_personagem)
  {
    ponteiro_extra=ponteiro_extra->next;
    if(ponteiro_extra->nome_personagem==personagem){
      ponteiro_extra->qtd_kills+=kills;
    }
    else if(personagem!=ponteiro_extra->nome_personagem && ponteiro_extra->next==NULL){
      cout<<"Tem certeza que digitou o nome certo? se não, tente novamente ";
      cin>> personagem;
      ponteiro_extra=ponteiro;
    }
  }
}

void ler_info(personagem *ponteiro){
  string pessoa;
  personagem *ponteiro_extra = new personagem();
  ponteiro_extra = ponteiro;
  cout<<"De quem você quer ler os stats? ";
  cin>> pessoa;
  cout<< endl<< endl;
  while (pessoa!=ponteiro_extra->nome_personagem)
  {
    ponteiro_extra=ponteiro_extra->next;
    if(ponteiro_extra->nome_personagem==pessoa){
      cout<<"O dano causado de "<<pessoa<<" foi de "<<ponteiro_extra->dano_causado<<endl;
      cout<<"O dano recebido de "<<pessoa<<" foi de: "<<ponteiro_extra->dano_recebido<<endl;
      cout<<"Os acertos criticos causados por "<<pessoa<<" foram de de: "<<ponteiro_extra->acertos_criticos<<endl;
      cout<<"Os erros criticos causados por "<<pessoa<<" foram de de: "<<ponteiro_extra->erros_critícos<<endl;
      cout<<pessoa<<" matou "<<ponteiro_extra->qtd_kills<<" mobs"<<endl<<endl;
    }
    else if(pessoa!=ponteiro_extra->nome_personagem && ponteiro_extra->next==NULL){
      cout<<"Tem certeza que digitou o nome certo? se não, tente novamente ";
      cin>> pessoa;
      ponteiro_extra=ponteiro;
    }
  }
}

void switch_case(personagem *ponteiro, int flag){
  switch (flag)
  {
  case 1:
    add_dmgcsd(ponteiro);
    break;
  case 2:
    add_dmgrcv(ponteiro);
    break;
  case 3:
    add_acertocrit(ponteiro);
    break;
  case 4:
    add_errocrit(ponteiro);
    break;
  case 5:
    add_kill(ponteiro);
    break;
  case 6:
    ler_info(ponteiro);
    break;
  case 7:
    cout<<"saindo do programa"<<endl;  
    break;
  default:
    cout<<"Opção não listada, digite novamente";
    break;
  }
}

void Menu(personagem *ponteiro){
  int flag;
  do{
    cout<<"     Que operação você deseja fazer?"<< endl<< endl;
    cout<<"Digite 1 para add dano causado"<< endl;
    cout<<"Digite 2 para add dano recebido"<< endl;
    cout<<"Digite 3 para add acerto critíco"<< endl;
    cout<<"Digite 4 para add erro critíco"<< endl;
    cout<<"Digite 5 para add adicionar uma Kill"<< endl;
    cout<<"Digite 6 para ver os stats de um personagem"<< endl;
    cout<<"Digite 7 para sair"<< endl;
    cin>> flag;
    switch_case(ponteiro, flag);
  } while(flag!=7);
}

void adicionar_nome(celula *p){
    celula *nova = new celula();
    string personagem;
    cout<<"Qual é o nome do personagem? ";
    cin>> personagem;
    nova->nome_personagem = personagem;
    nova->next = p->next;
    p->next= nova;
}

void Ler_Nomes(celula *personagem){
  int flag;
  cout<<"Digite 1 para add um personagem"<<endl;
  cout<<"Digite 0 para sair"<<endl;
  cin>>flag;
  while (flag==1)
  {
    adicionar_nome(personagem);
    cout<<"Digite novamente 0 ou 1"<<endl;
    cin>>flag;
  }
}

int main(){
  personagem *herois = new personagem();
  Ler_Nomes(herois);
  Menu(herois);
  return 0;

}