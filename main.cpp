#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "Funcao.h"
#include "Grafico.h"
#include "Calculo_Numerico.h"
#include "Calculo_Analitico.h"

std::string ler_input(int &aluno, double &p1, double &p2, double &p3, double &d1, double &d2, double &d3, double &li1, double &ls1, double &li2, double &ls2, double &li3, double &ls3);

int main(){

   std::string func;
   int aluno;
   double p1, p2, p3, d1, d2, d3, li1, ls1, li2, ls2, li3, ls3;

    func = ler_input(aluno, p1, p2, p3, d1, d2, d3, li1, ls1, li2, ls2, li3, ls3);
   
    FILE* saida = fopen("RELATORIO.txt", "w");
    if(saida == NULL) {
        fprintf(stderr, "Erro ao criar o arquivo.");
    }
    fclose(saida);

   if (aluno == 1 )
   {
      Funcao f1(func);
      if(f1.get_tipo_Polinomio()){
        f1.get_dominio();
        f1.get_imagem();
        f1.plot(); 
        double F1_x1 = f1.retorna_valor(p1);
        double F1_x2 = f1.retorna_valor(p2);
        double F1_x3 = f1.retorna_valor(p3);


        std::ofstream outfile;	
        outfile.open("RELATORIO.txt",  std::ios::app);
        outfile << "\n*===========f(x) no ponto dado============* " << std::endl;
        outfile << "\nf(" << p1 << ") = " << F1_x1 << std::endl;
        outfile << "\nf(" << p2 << ") = " << F1_x2 << std::endl;
        outfile << "\nf(" << p3 << ") = " << F1_x3 << std::endl;
        outfile.close();
      }
      else
      {
        f1.plot(); 
        double F1_x1 = f1.retorna_valor(p1);
        double F1_x2 = f1.retorna_valor(p2);
        double F1_x3 = f1.retorna_valor(p3);


        std::ofstream outfile;	
        outfile.open("RELATORIO.txt",  std::ios::app);
        outfile << "\n*===========f(x) no ponto dado============* " << std::endl;
        outfile << "\nf(" << p1 << ") = " << F1_x1 << std::endl;
        outfile << "\nf(" << p2 << ") = " << F1_x2 << std::endl;
        outfile << "\nf(" << p3 << ") = " << F1_x3 << std::endl;
        outfile.close();
      }
   } 

   if (aluno == 2 )
   {
      Funcao f1(func);
      if(f1.get_tipo_Polinomio()){

        Calculo_Analitico f3(func);
        f3.get_dominio();
        f3.get_imagem(); 
        f3.get_max_e_min();
        f3.plot(); 

        double   F3_x1  = f3.retorna_valor(p1);
        double   F3_x2  = f3.retorna_valor(p2);
        double   F3_x3  = f3.retorna_valor(p3); 
        double d_F3_x1  = f3.retorna_valor("derivada", d1);
        double d_F3_x2  = f3.retorna_valor("derivada", d2);
        double d_F3_x3  = f3.retorna_valor("derivada", d3);
        double i_F3_ab1  = f3.retorna_valor("integral", li1, ls1);
        double i_F3_ab2  = f3.retorna_valor("integral", li2, ls2);
        double i_F3_ab3  = f3.retorna_valor("integral", li3, ls3); 

        Calculo_Numerico f2(func);

        double d_F2_x1  = f2.retorna_valor("derivada", d1);
        double d_F2_x2  = f2.retorna_valor("derivada", d2);
        double d_F2_x3  = f2.retorna_valor("derivada", d3);
        double i_F2_ab1  = f2.retorna_valor("integral", li1, ls1);
        double i_F2_ab2  = f2.retorna_valor("integral", li2, ls2);
        double i_F2_ab3  = f2.retorna_valor("integral", li3, ls3);


        std::ofstream outfile;	
        outfile.open("RELATORIO.txt",  std::ios::app);
        outfile << "\n*===========f(x) no ponto dado============* " << std::endl;
        outfile << "\nf(" << p1 << ") = " << F3_x1 << std::endl;
        outfile << "\nf(" << p2 << ") = " << F3_x2 << std::endl;
        outfile << "\nf(" << p3 << ") = " << F3_x3 << std::endl;
        outfile << "\n*===========f'(x) no ponto dado (analitica)============* " << std::endl;
        outfile << "\nf\'(" << d1 << ") = " << d_F3_x1 << std::endl;
        outfile << "\nf\'(" << d2 << ") = " << d_F3_x2 << std::endl;
        outfile << "\nf\'(" << d3 << ") = " << d_F3_x3 << std::endl;
        outfile << "\n*===========integral de f(x) no intervalo dado (analitica)============* " << std::endl;
        outfile << "\nIntegral de f de " << li1 << " até " << ls1 << " = " << i_F3_ab1 << std::endl;
        outfile << "\nIntegral de f de " << li2 << " até " << ls2 << " = " << i_F3_ab2 << std::endl;
        outfile << "\nIntegral de f de " << li3 << " até " << ls3 << " = " << i_F3_ab3 << std::endl;
        outfile << "\n*===========f'(x) no ponto dado (numerico)============* " << std::endl;
        outfile << "\nAproximacao numerica da f\'(" << d1 << ") = " << d_F2_x1 << std::endl;
        outfile << "\nAproximacao numerica da f\'(" << d2 << ") = " << d_F2_x2 << std::endl;
        outfile << "\nAproximacao numerica da f\'(" << d3 << ") = " << d_F2_x3 << std::endl;
        outfile << "\n*===========integral de f(x) no intervalo dado (numerico)============* " << std::endl;
        outfile << "\nAproximacao numerica da integral de f de " << li1 << " até " << ls1 << " = " << i_F2_ab1 << std::endl;
        outfile << "\nAproximacao numerica da integral de f de " << li2 << " até " << ls2 << " = " << i_F2_ab2 << std::endl;
        outfile << "\nAproximacao numerica da integral de f de " << li3 << " até " << ls3 << " = " << i_F2_ab3 << std::endl;
        outfile.close();

      }
      else
      {
        Calculo_Numerico f2(func);

        f2.plot();
        double   F2_x1  = f2.retorna_valor(p1);
        double   F2_x2  = f2.retorna_valor(p2);
        double   F2_x3  = f2.retorna_valor(p3);
        double d_F2_x1  = f2.retorna_valor("derivada", d1);
        double d_F2_x2  = f2.retorna_valor("derivada", d2); 
        double d_F2_x3  = f2.retorna_valor("derivada", d3); 
        double i_F2_ab1  = f2.retorna_valor("integral", li1, ls1);
        double i_F2_ab2  = f2.retorna_valor("integral", li2, ls2); 
        double i_F2_ab3  = f2.retorna_valor("integral", li3, ls3);

        std::ofstream outfile;	
        outfile.open("RELATORIO.txt",  std::ios::app);
        outfile << "\n*===========f(x) no ponto dado============* " << std::endl;
        outfile << "\nf(" << p1 << ") = " << F2_x1 << std::endl;
        outfile << "\nf(" << p2 << ") = " << F2_x2 << std::endl;
        outfile << "\nf(" << p3 << ") = " << F2_x3 << std::endl;
        outfile << "\n*===========f'(x) no ponto dado (numerico)============* " << std::endl;
        outfile << "\naproximacao numerica da f\'(" << d1 << ") = " << d_F2_x1 << std::endl;
        outfile << "\naproximacao numerica da f\'(" << d2 << ") = " << d_F2_x2 << std::endl;
        outfile << "\naproximacao numerica da f\'(" << d3 << ") = " << d_F2_x3 << std::endl;
        outfile << "\n*===========integral de f(x) no intervalo dado (numerico)============* " << std::endl;
        outfile << "\naproximacao numerica da integral de f de " << li1 << " até " << ls1 << " = " << i_F2_ab1 << std::endl;
        outfile << "\naproximacao numerica da integral de f de " << li2 << " até " << ls2 << " = " << i_F2_ab2 << std::endl;
        outfile << "\naproximacao numerica da integral de f de " << li3 << " até " << ls3 << " = " << i_F2_ab3 << std::endl;
        outfile.close();
      }
   } 


   return 0;
}

std::string ler_input(int &aluno, double &p1, double &p2, double &p3, double &d1, double &d2, double &d3, double &li1, double &ls1, double &li2, double &ls2, double &li3, double &ls3){

   std::string leia, func;

   std::ifstream entrada;
   entrada.open("INPUT.txt");

  if (entrada.is_open() && entrada.good())
  { std::getline(entrada, leia);

    while(!entrada.fail())
     {
        if (leia[0] != '#')
        {
                switch(leia[0]){
                 case 'a' :
                   entrada >> aluno;
                   break;
                 case 'f' :
                   std::getline(entrada, func);
                   break;
                 case 'p' :
                   {switch(leia[1]){
                      case '1' :
                       entrada >> p1;
                       break;
                      case '2' :
                       entrada >> p2;
                       break;
                      case '3' :
                       entrada >> p3;
                       break;
                     }                       
                    }
                   break;
                 case 'd' :
                   {switch(leia[1]){
                      case '1' :
                       entrada >> d1;
                       break;
                      case '2' :
                       entrada >> d2;
                       break;
                      case '3' :
                       entrada >> d3;
                       break;
                     }                      
                    }
                   break;
                 case 'i' :
                   {switch(leia[1]){
                      case '1' :
                       entrada >> li1 >> ls1;
                       break;
                      case '2' :
                       entrada >> li2 >> ls2;
                       break;
                      case '3' :
                       entrada >> li3 >> ls3;
                       break;
                     }
                    }
                   break;
                }

        }

         std::getline(entrada, leia);        
     }
   }

   entrada.close();

 
   return func;
}






































