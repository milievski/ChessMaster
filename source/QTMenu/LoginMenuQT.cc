#include "LoginMenuQT.h"

LoginMenuQT::LoginMenuQT(QWidget *parent)
{

}


void LoginMenuQT::loadCreatePlayer(const QString &name, RegisteredPlayer* &p)
{

   Database data;
   //DOES PLAYEREXIST IS ALWAYS RETURNING TRUE, KILLS FUNCTIONALITY HERE
   if(data.doesPlayerExist(name.toStdString()))
   {
      p->restoreMemento(data.loadPlayer(name.toStdString()));
   }
   else
   {
      //SAVED PLAYERS IS NOT CREATING ANY FILES EITHER
      data.savePlayer(p->generateMemento(), name.toStdString());
      p->restoreMemento(data.loadPlayer(name.toStdString()));
   }
   
}

//string LoginMenu::EnterName()
void LoginMenuQT::loadPlayerSlot(const QString &name)
{

}
