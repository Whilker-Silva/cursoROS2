# Integração ROS 2 + PX4

Para realizar as instalação, execute no terminal os comandos abaixo um de cada vez, se encontrar problemas de instalação, bugs ou erros de dependências, as ferramentas baseadas em IA como o Chat GPT têm se mostrado excelentes para resolver esse tipo de problema.

💡 Dica: copiem e colem os comandos e os erros completos — vocês vão se surpreender com a precisão das respostas.

---

## 📋 Requisitos de Sistema

- Um PC com pelo menos 64 GB de espaço de armazenamento.
- **Sistema Operacional:** Ubuntu 22.04 LTS
- **ROS 2:** Humble (LTS)

---

## ⚙️ Instalação no Ubuntu

A versão mais recomendada do Ubuntu para trabalhar com o PX4 é a **22.04 LTS**.

Mesmo que você já tenha outra versão instalada, é fortemente recomendado o uso desta versão, pois ela possui o maior suporte da comunidade e melhor compatibilidade com os pacotes necessários.

Uma sugestão caso já utilize outro sistema operacional, é realizar a instalação do Ubuntu em dual boot ou máquina virtual que permitirá você usar mais de um sistema operacional no mesmo computador.

Link oficial com passo a passo para instalação Ubuntu 22.04

[Install Ubuntu Desktop](https://ubuntu.com/tutorials/install-ubuntu-desktop#1-overview)

Sugestão de como instalar em dual boot, contudo não se esqueça que usar a versão 22.04 LTS

[Como instalar Ubuntu junto do Windowns 11](https://www.youtube.com/watch?v=QrsDuBwgF9Y&ab_channel=MWInform%C3%A1tica)

---

## 🤖 Instalação do ROS 2 

### Passo 1: Atualizar pacotes

```bash
sudo apt update
sudo apt upgrade
```

### Passo 2: Definir localidade
Certifique-se de ter uma localidade compatível com `UTF-8` para isso digite no terminal o comando `locale` , caso a resposta seja uma localidade não compatível, use o seguintes comandos.

```bash
sudo apt update && sudo apt install locales
sudo locale-gen en_US en_US.UTF-8
sudo update-locale LC_ALL=en_US.UTF-8 LANG=en_US.UTF-8
export LANG=en_US.UTF-8
```

.
.
.

[Como instalar](https://rift-sunspot-acb.notion.site/Integra-o-ROS-2-PX4-1dfef3fa298080deb8c7f0b4951a7487)

.
.
.




