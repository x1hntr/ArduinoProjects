        
        int su;
        int sd;
        int mu;
        int md;
    
        int uv=0;
        int dv=0;
        int ul=0;
        int dl=0;

        int fl=0;
        int fv=0;
        
        int a=0;
        int b=0;
        int c=0;
        int d=0;
      
        int equipo;
        int pausa;
        int puntos;
        int puntosm;
        int periodo=1;
        
        const int LOCAL = A11;
        const int VISITA = A12;
        int pause = 0;
        void setup() {
            Serial.begin(9600);
          //PINES DEL RELOJ
            pinMode(13, OUTPUT);
          
            pinMode(2, OUTPUT); 
            pinMode(3, OUTPUT); 
            pinMode(4, OUTPUT);
            pinMode(5, OUTPUT); 
        
            pinMode(6, OUTPUT); 
            pinMode(7, OUTPUT); 
            pinMode(8, OUTPUT);
        
            pinMode(9, OUTPUT); 
            pinMode(10, OUTPUT); 
            pinMode(11, OUTPUT);
            pinMode(12, OUTPUT); 
        
            pinMode(23, OUTPUT); 
            pinMode(25, OUTPUT); 
            pinMode(27, OUTPUT);
        
            
            
          //PINES DEL LOS MARCADORES VISITA
            pinMode(23, OUTPUT); 
            pinMode(25, OUTPUT); 
            pinMode(27, OUTPUT);
            pinMode(29, OUTPUT); 
        
            pinMode(31, OUTPUT); 
            pinMode(33, OUTPUT); 
            pinMode(35, OUTPUT);
            pinMode(37, OUTPUT); 
        
           //PINES DEL LOS MARCADORES LOCAL
            pinMode(39, OUTPUT); 
            pinMode(41, OUTPUT); 
            pinMode(43, OUTPUT);
            pinMode(45, OUTPUT); 
        
            pinMode(47, OUTPUT); 
            pinMode(49, OUTPUT); 
            pinMode(51, OUTPUT);
            pinMode(53, OUTPUT); 
            
            //PINES DE FALTAS
            pinMode(14, OUTPUT);
            pinMode(15, OUTPUT);
            pinMode(16, OUTPUT);
        
            pinMode(17, OUTPUT);
            pinMode(18, OUTPUT);
            pinMode(19, OUTPUT);
        
            //PINES DE MARCADOR
            pinMode(20, OUTPUT);
            pinMode(21, OUTPUT);
            pinMode(22, OUTPUT);
            Serial.begin(9600);
      
            //PULSADORES
            pinMode(24, INPUT);
            pinMode(26, INPUT);
            pinMode(28, INPUT);
            pinMode(30, INPUT);
            pinMode(32, OUTPUT);
            pinMode(34, OUTPUT);
            pinMode(36, INPUT);
            pinMode(38, OUTPUT);
            pinMode(40, OUTPUT);
            
            //LEDS
            pinMode(LOCAL, OUTPUT);
            pinMode(VISITA, OUTPUT);
      
            ///INICIAR MARCADORES
            numeros_unitarios(0, 8, 6, 7);
            numeros_unitarios(0, 17, 19, 18);
            digitalWrite(13, HIGH);
            numeros(dv, 5, 2, 3, 4);               //DECENA VISITA
            numeros(uv, 12, 9, 10, 11);            //UNIDADES VISITA
            numeros(dl, 23, 29, 27, 25);           //DECENAS LOCAL
            numeros(ul, 39, 45, 43, 41);           //UNIDADES LOCAL
      
            
        }
        //U1: numeros(muv, 5, 2, 3, 4);               //DECENA VISITA
        //U2: numeros_unitarios(mdv, 8, 6, 7);        //FALTA VISITA
        //U3: numeros(muv, 12, 9, 10, 11);            //UNIDADES VISITA
        //U4: este es solo 1 numero
        //U5: numeros(muv, 23, 29, 27, 25);           //DECENAS LOCAL
        //U6: numeros(muv, 31, 37, 35, 33);           //UNIDADES MINUTOS CRONO
        //U7: numeros(muv, 39, 45, 43, 41);           //UNIDADES LOCAL
        //U8: numeros(muv, 47, 53, 51, 49);           //UNIDADES SEGUNDOS CRONO
        //U9: numeros_unitarios(muv, 14, 16, 15);     //PERIODO    
        //U10: numeros_unitarios(muv, 17, 19, 18);    //FALTA LOCAL
        //U11: numeros_unitarios(muv, 20, 22, 21);    //DECENAS SEGUNDOS CRONO
        
        
        void loop() {
        if (digitalRead(26) == HIGH){
                pausa = 1;
                delay(500);
                }
                
                while(pausa == 1){
                  if (digitalRead(28) == HIGH){        
                delay(500);
                }
       
        for(periodo = 1; periodo<4; periodo++){ 
          for(int mu=9; mu>=0; mu--){
            for(int sd=5; sd>=0; sd--){
              for(int su=9; su>=0; su--){
                     
              if (digitalRead(26) == HIGH){
                pausa = 1;
                delay(500);
                }
                
                while(pausa == 1){
                  if (digitalRead(28) == HIGH){
                mu=9;
                sd=5;
                su=9;          
         
                }
                if (digitalRead(26) == HIGH){
                pausa = 0;
                
                delay(500);
                }
                }
              if (digitalRead(28) == HIGH){
                mu=9;
                sd=5;
                su=9;          
                delay(500);
                }
               
                
              numeros(su, 47, 53, 51, 49);
              numeros_unitarios(sd, 20, 22, 21);
              numeros(mu, 31, 37, 35, 33);
              digitalWrite(13, LOW);  
              numeros_unitarios(periodo, 14, 16, 15);      
              equipo = digitalRead(24);
              if(equipo == 1){
                digitalWrite(LOCAL, HIGH);
                digitalWrite(VISITA, LOW);
                }
              if(equipo == 0){
                digitalWrite(VISITA, HIGH);
                digitalWrite(LOCAL, LOW);
          }
          puntos = digitalRead(30);        
              if(puntos == 1 && equipo == 1){
              ul++;
              if(ul==10){
                ul=0;
                dl++;
                }
        numeros(dl, 23, 29, 27, 25);           //DECENAS LOCAL
        numeros(ul, 39, 45, 43, 41);           //UNIDADES LOCAL
                }
              if(puntos == 1 && equipo == 0){
              uv++;
              if(uv==10){
                uv=0;
                dv++;
                }
        numeros(dv, 5, 2, 3, 4);               //DECENA VISITA
        numeros(uv, 12, 9, 10, 11);            //UNIDADES VISITA
                }
       puntosm = digitalRead(32);
             
           if(puntosm == 1 && equipo == 1){
              ul--;
              if(ul==0){
                ul=9;
                dl--;
                }
        numeros(dl, 23, 29, 27, 25);           //DECENAS LOCAL
        numeros(ul, 39, 45, 43, 41);           //UNIDADES LOCAL
                }
              if(puntosm == 1 && equipo == 0){
              uv--;
              if(uv==0){
                uv=9;
                dv--;
                }
        numeros(dv, 5, 2, 3, 4);               //DECENA VISITA
        numeros(uv, 12, 9, 10, 11);            //UNIDADES VISITA
                }


        if(puntos = digitalRead(34) == 1 && equipo == 1){
              ul=0;
              dl=0;
        numeros(dl, 23, 29, 27, 25);           //DECENAS LOCAL
        numeros(ul, 39, 45, 43, 41);           //UNIDADES LOCAL
                }
        if(puntos = digitalRead(34) == 1  && equipo == 0){
              uv=0;
              dv=0;
        numeros(dv, 5, 2, 3, 4);               //DECENA VISITA
        numeros(uv, 12, 9, 10, 11);            //UNIDADES VISITA
                }
                
        if(puntos = digitalRead(36) == 1 && equipo == 0){
              fl++;
        numeros_unitarios(fl, 8, 6, 7);        //FALTA VISITA
                }            
            if(puntos = digitalRead(36) == 1 && equipo == 1){
              fv++;       
        numeros_unitarios(fv, 17, 19, 18);    //FALTA LOCAL
                } 
        if(puntos = digitalRead(38) == 1 && equipo == 0){
              fl--;
        numeros_unitarios(fl, 8, 6, 7);        //FALTA VISITA
                }            
            if(puntos = digitalRead(38) == 1 && equipo == 1){
              fv--;       
        numeros_unitarios(fv, 17, 19, 18);    //FALTA LOCAL
                }             


        //RESET FALTAS
        if(puntos = digitalRead(40) == 1 && equipo == 0){
              fl=0;
        numeros_unitarios(fl, 8, 6, 7);        //FALTA VISITA
                }            
            if(puntos = digitalRead(40) == 1 && equipo == 1){
              fv=0;       
        numeros_unitarios(fv, 17, 19, 18);    //FALTA LOCAL
                }   

                
                delay(500);
          }
          
          }
          }
            
                
       
        //DESCANSOS
        if(periodo == 1){
           for(int md=0; md>=0; md--){
          for(int mu=1; mu>=0; mu--){
            for(int sd=5; sd>=0; sd--){
              for(int su=9; su>=0; su--){
              numeros(su, 47, 53, 51, 49);
              numeros_unitarios(sd, 20, 22, 21);
              numeros(mu, 31, 37, 35, 33);
              digitalWrite(13, LOW);  
              numeros_unitarios(periodo, 14, 16, 15);
              delay(1000);    
          }
          }
          }
          }
          }
          if(periodo == 2 ||periodo == 3 ){
           for(int md=0; md>=0; md--){
          for(int mu=4; mu>=0; mu--){
            for(int sd=5; sd>=0; sd--){
              for(int su=9; su>=0; su--){
              numeros(su, 47, 53, 51, 49);
              numeros_unitarios(sd, 20, 22, 21);
              numeros(mu, 31, 37, 35, 33);
              digitalWrite(13, LOW);  
              numeros_unitarios(periodo, 14, 16, 15);
              delay(1000);
              
              
          }
          }
          }
          }
          }    
          }
        }
      
        }
      
      
      
        
        void numeros(int i, int a, int b, int c, int d){
            switch (i) {
            case 0:
              digitalWrite(a, LOW);
              digitalWrite(b, LOW);
              digitalWrite(c, LOW);
              digitalWrite(d, LOW);
              break;
            case 1:
              digitalWrite(a, HIGH);
              digitalWrite(b, LOW);
              digitalWrite(c, LOW);
              digitalWrite(d, LOW);
              break;
            case 2:
              digitalWrite(a, LOW);
              digitalWrite(b, HIGH);
              digitalWrite(c, LOW);
              digitalWrite(d, LOW);
              break;
            case 3:
              digitalWrite(a, HIGH);
              digitalWrite(b, HIGH);
              digitalWrite(c, LOW);
              digitalWrite(d, LOW);
              break;
            case 4:
              digitalWrite(a, LOW);
              digitalWrite(b, LOW);
              digitalWrite(c, HIGH);
              digitalWrite(d, LOW);
              break;
            case 5:
              digitalWrite(a, HIGH);
              digitalWrite(b, LOW);
              digitalWrite(c, HIGH);
              digitalWrite(d, LOW);
              break;
              case 6:
              digitalWrite(a, LOW);
              digitalWrite(b, HIGH);
              digitalWrite(c, HIGH);
              digitalWrite(d, LOW);
              break;
              case 7:
              digitalWrite(a, HIGH);
              digitalWrite(b, HIGH);
              digitalWrite(c, HIGH);
              digitalWrite(d, LOW);
              break;
              case 8:
              digitalWrite(a, LOW);
              digitalWrite(b, LOW);
              digitalWrite(c, LOW);
              digitalWrite(d, HIGH);
              break;
              case 9:
              digitalWrite(a, HIGH);
              digitalWrite(b, LOW);
              digitalWrite(c, LOW);
              digitalWrite(d, HIGH);
              break;
          }
            }
        
            void numeros_unitarios(int i, int a, int b, int c){
            switch (i) {
            case 0:
              digitalWrite(a, LOW);
              digitalWrite(b, LOW);
              digitalWrite(c, LOW);
              break;
            case 1:
              digitalWrite(a, HIGH);
              digitalWrite(b, LOW);
              digitalWrite(c, LOW);
              break;
            case 2:
              digitalWrite(a, LOW);
              digitalWrite(b, HIGH);
              digitalWrite(c, LOW);
              break;
            case 3:
              digitalWrite(a, HIGH);
              digitalWrite(b, HIGH);
              digitalWrite(c, LOW);
              break;
            case 4:
              digitalWrite(a, LOW);
              digitalWrite(b, LOW);
              digitalWrite(c, HIGH);
              break;
            case 5:
              digitalWrite(a, HIGH);
              digitalWrite(b, LOW);
              digitalWrite(c, HIGH);
              break;
          }
            }
