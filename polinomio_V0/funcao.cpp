#include <iostream>
#include <sstream>
#include <math.h>
#include <cstring>
#include <iomanip>
#include <stdio.h>
#include <string.h>
#include <string>
#include "funcao.h"
 
using namespace std;

Funcao::Funcao(char entrada[100])
{
   char *pch, *pch2, *p, *q;
   int j=0, k=0, l=0, n=21;
   char **dadosP, **dadosN, **dados;
   int coef[10], pot[10], index=0;

   dadosP = new char*[n]();
   for (int i=0; i < n; i++)
      dadosP[i] = new char[20]();

   dadosN = new char*[n]();
   for (int i=0; i < n; i++)
      dadosN[i] = new char[20]();

   dados = new char*[n]();
   for (int i=0; i < n; i++)
      dados[i] = new char[20]();


// Caso o primeiro coeficiente seja positivo

   if (entrada[0] == '+'){
      pch = strtok (entrada,"+");
      while (pch != NULL)
      {
        dados[l] = pch;
        l++;
        pch = strtok (NULL, "+");
      }



      for (int i=0; i < l; i++){
         string str = dados[i];
         char * cstr = new char [str.length()+1];
         strcpy (cstr, str.c_str());

         p = strstr(cstr, "-");
 

         if (p != NULL){
              pch2 = strtok (cstr,"-");
              dadosP[j] = pch2;
              j++;
              while (pch2 != NULL)
              {
                 pch2 = strtok (NULL, "-");
                 dadosN[k] = pch2;
                 k++;
              }
              k--;
           }
           else{
              dadosP[j] = cstr;
              j++;
           }
      }

/*    Essa parte era para ver se estava quebrando certo :)

      cout << "Dados" << endl;

      for (int i=0; i < l; i++)
         cout << dados[i]<< endl;

      cout << "DadosP" << endl;

      for (int i=0; i < j; i++)
         cout << dadosP[i] << endl;

      cout << "DadosN" << endl;

      for (int i=0; i < k; i++)
         cout << dadosN[i]<< endl;
*/


      string::size_type sz; // Juro que não sei pq isso!!

      //"DadosP" 

      for (int i=0; i < j; i++){


         string str = dadosP[i];
         char * cstr = new char [str.length()+1];
         strcpy (cstr, str.c_str());

         p = strstr(cstr, "x");

         if (p != NULL){
            
            q = strstr(cstr, "**");

            if (q != NULL){


              pch2 = strtok (cstr,"*");
              string str2 = pch2;
              coef[index] = stoi (str2,&sz);
              string str3 = "vazio";

              while (pch2 != NULL)
              {
                 str3 = pch2;
                 pch2 = strtok (NULL, "*");
              }

              pot[index]  = stoi (str3,&sz);
              index++;

            }else{

              pch2 = strtok (cstr,"*");
              string str2 = pch2;
              coef[index] = stoi (str2,&sz);
              pot[index]  = 1;
              index++;

            }



         }else{
            coef[index] = stoi (str,&sz);
            pot[index]  = 0;
            index++;
         }
      
      }

      // "DadosN"

      for (int i=0; i < k; i++){


         string str = dadosN[i];
         char * cstr = new char [str.length()+1];
         strcpy (cstr, str.c_str());

         p = strstr(cstr, "x");

         if (p != NULL){
            
            q = strstr(cstr, "**");

            if (q != NULL){


              pch2 = strtok (cstr,"*");
              string str2 = pch2;

              int aux = stoi (str2,&sz);
              coef[index] = aux*(-1);

              string str3 = "vazio";

              while (pch2 != NULL)
              {
                 str3 = pch2;
                 pch2 = strtok (NULL, "*");
              }

              pot[index]  = stoi (str3,&sz);
              index++;

            }else{

              pch2 = strtok (cstr,"*");
              string str2 = pch2;
              int aux = stoi (str2,&sz);
              coef[index] = aux*(-1); 
              pot[index]  = 1;
              index++;

            }



         }else{
            int aux = stoi (str,&sz);
            coef[index] = aux*(-1);
            pot[index]  = 0;
            index++;
         }
      
      }


   }

// Caso o primeiro coeficiente seja negativo

   if (entrada[0] == '-'){
      pch = strtok (entrada,"-");
      while (pch != NULL)
      {
        dados[l] = pch;
        l++;
        pch = strtok (NULL, "-");
      }



      for (int i=0; i < l; i++){
         string str = dados[i];
         char * cstr = new char [str.length()+1];
         strcpy (cstr, str.c_str());

         p = strstr(cstr, "+");
 

         if (p != NULL){
              pch2 = strtok (cstr,"+");
              dadosN[j] = pch2;
              j++;
              while (pch2 != NULL)
              {
                 pch2 = strtok (NULL, "+");
                 dadosP[k] = pch2;
                 k++;
              }
              k--;
           }
           else{
              dadosN[j] = cstr;
              j++;
           }
      }

/*    Essa parte era para ver se estava quebrando certo :)

      cout << "Dados" << endl;

      for (int i=0; i < l; i++)
         cout << dados[i]<< endl;

      cout << "DadosP" << endl;

      for (int i=0; i < k; i++)
         cout << dadosP[i] << endl;

      cout << "DadosN" << endl;

      for (int i=0; i < j; i++)
         cout << dadosN[i]<< endl;
*/


      string::size_type sz; // Juro que não sei pq isso!!

      //"DadosP" 

      for (int i=0; i < k; i++){


         string str = dadosP[i];
         char * cstr = new char [str.length()+1];
         strcpy (cstr, str.c_str());

         p = strstr(cstr, "x");

         if (p != NULL){
            
            q = strstr(cstr, "**");

            if (q != NULL){


              pch2 = strtok (cstr,"*");
              string str2 = pch2;
              coef[index] = stoi (str2,&sz);
              string str3 = "vazio";

              while (pch2 != NULL)
              {
                 str3 = pch2;
                 pch2 = strtok (NULL, "*");
              }

              pot[index]  = stoi (str3,&sz);
              index++;

            }else{

              pch2 = strtok (cstr,"*");
              string str2 = pch2;
              coef[index] = stoi (str2,&sz);
              pot[index]  = 1;
              index++;

            }



         }else{
            coef[index] = stoi (str,&sz);
            pot[index]  = 0;
            index++;
         }
      
      }

      // "DadosN"

      for (int i=0; i < j; i++){


         string str = dadosN[i];
         char * cstr = new char [str.length()+1];
         strcpy (cstr, str.c_str());

         p = strstr(cstr, "x");

         if (p != NULL){
            
            q = strstr(cstr, "**");

            if (q != NULL){


              pch2 = strtok (cstr,"*");
              string str2 = pch2;

              int aux = stoi (str2,&sz);
              coef[index] = aux*(-1);

              string str3 = "vazio";

              while (pch2 != NULL)
              {
                 str3 = pch2;
                 pch2 = strtok (NULL, "*");
              }

              pot[index]  = stoi (str3,&sz);
              index++;

            }else{

              pch2 = strtok (cstr,"*");
              string str2 = pch2;
              int aux = stoi (str2,&sz);
              coef[index] = aux*(-1); 
              pot[index]  = 1;
              index++;

            }



         }else{
            int aux = stoi (str,&sz);
            coef[index] = aux*(-1);
            pot[index]  = 0;
            index++;
         }
      
      }


   }

   for (int i=0; i < index; i++){
     _coef[i] = coef[i];
     _pot[i]  = pot[i];
   }
  _index = index;

}

Funcao::~Funcao()
{
}


void Funcao::determinaFX0(int input_x0)
{
   long int retorno = 0;

   for (int i=0; i < _index; i++)
      retorno += _coef[i]*pow(input_x0,_pot[i]);
  
   cout << "f(" << input_x0 << ") = " << retorno << endl;
}


void Funcao::derivada_em_X0(double input_x0)
{
   double derivada;
   double h=0.001;

   double xMenos = input_x0 - h;
   double xMais = input_x0 + h;

   double retornoMenos = 0;
   double retornoMais = 0;

   for (int i=0; i < _index; i++){
      double aux1 = (double) _coef[i];
      double aux2 = (double) _pot[i];
      retornoMenos += aux1*pow(xMenos,aux2);
   }

   for (int i=0; i < _index; i++){
      double aux1 = (double) _coef[i];
      double aux2 = (double) _pot[i];
      retornoMais += aux1*pow(xMais,aux2);
   }

   derivada = (retornoMais - retornoMenos)/(2.*h);
  
   cout << "f'(" << input_x0 << ") = " << derivada << endl;
}


