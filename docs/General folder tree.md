# Project's folder tree
Aixt project has the follow general folder tree:
    
```
aixt/    
    ├── aixt_build
    │   └── builder.v
    ├── aixt_cgen
    │   ├── assign.v
    │   ├── call.v
    :   :
    │   └── utils.v
    ├── aixt.v
    ├── assets
    │   ├── Aixtu-ru.jpeg
    │   ├── Aixtu-ru-wide.png
    :   :
    │   └── text-logo.svg
    ├── common_test
    │   ├── 00_one_line.v
    │   ├── 01_declaring_and_types.v
    :   :
    │   ├── 29_types.v
    ├── CONTRIBUTING.md
    ├── docs
    │   ├── Aixt language.md
    │   ├── API folder tree.md
    :   :
    │   ├── Setup file.md
    │   ├── Atmel
    │   ├── Cypress
    :   :
    │   └── WCH
    ├── LICENSE
    ├── ports
    │   ├── Atmel
    │   ├── Cypress
    :   :
    │   └── WCH
    ├── prerequisites.md
    ├── README.md
    ├── TODO.md
    └── v.mod
```

- The _source code_ is located in `aixt.v` file, and `aixt_build/`, `aixt_cgen/` folders.
- The `assets` folder contains the resource files such images.
- The `ports` folder contains the implementation code for each device or board (mainly C source code)
- The `docs` folder contains the documentation for each device or board

