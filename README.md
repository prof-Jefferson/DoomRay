# DoomRay — Curso FIC (Formação Inicial e Continuada)

Projeto didático em **C++20 + SFML** para ensinar conceitos de **raycasting** ao estilo clássico do DOOM.  
A janela é dividida em **duas telas**:
- **Esquerda**: visão 2D (mapa/top-down)  
- **Direita**: visão 3D (raycasting/fake 3D)  

O desenvolvimento é incremental, cada commit é **enumerado** (`c00`, `c01`, …) para facilitar o aprendizado.

---

## Pré-requisitos

O projeto usa **C++20** e algumas bibliotecas de terceiros.  
No Linux (Ubuntu/Xubuntu/Debian), instale com:

```bash
# Compilador e ferramentas básicas
sudo apt update
sudo apt install g++ cmake make git

# Biblioteca gráfica (SFML)
sudo apt install libsfml-dev
