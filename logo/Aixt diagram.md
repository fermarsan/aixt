```mermaid
%%{ init: { 'theme': 'base', 
            'themeVariables': { 'primaryColor': '#847160',
                                'secondaryColor': '#6f7c84',
                                'primaryTextColor': '#efece7',
                                'primaryBorderColor': '#372a21',
                                'tertiaryTextColor': '#c3c2f',
                                'tertiaryBorderColor': '#472a21',
                                'lineColor': '#372a21'
                              }
          }
}%%

stateDiagram-v2

    Aixt: Aixt language
    state Aixt {
        source: Source code
        API
    }

    Aixt2C: Aixt to C\nTranspiler

    C: C language
    state C {
        state join_C <<fork>>
        Tr_Code: Transpiled code
        API_C: API in C
        Tr_Code --> join_C
        API_C --> join_C
    }

    state Microcontrollers {
        PICs: PICXX
        ATM: AT Mega
        ATT: AT Tiny
        others2: ...
        ESP32
        RP2040
    }

    C_Compiler: C Compiler
    state C_Compiler {
        others: ...
        XC8  
        XC16 
        ImageCraft  
        others 
        GCC 
    }
    
    machine
    state machine {
        BF: Binary file
    }
    
    source  --> Aixt2C
    API     --> Aixt2C 
    Aixt2C  --> Tr_Code

    join_C     --> C_Compiler

    C_Compiler  --> machine

    Microcontrollers --> API_C

%% general block diagram in mermaid.js
%% converted in svg image by using https://mermaid.live/edit
```