# Integração ROS 2 + PX4

Este guia apresenta o passo a passo para integrar o ROS 2 com o PX4, incluindo os requisitos de sistema, comandos de instalação e execução de exemplo.

---

## 📋 Requisitos de Sistema

- **Sistema Operacional:** Ubuntu 20.04 ou 22.04
- **ROS 2:** Humble (LTS)
- **PX4:** v1.14 ou superior

---

## ⚙️ Instalação no Ubuntu

### Instalação do ROS 2

```bash
sudo apt update && sudo apt upgrade -y
sudo apt install curl gnupg2 lsb-release
curl -sSL https://raw.githubusercontent.com/ros/rosdistro/master/ros.key | sudo apt-key add -
sudo sh -c 'echo "deb [arch=amd64] https://packages.ros.org/ros2/ubuntu $(lsb_release -cs) main" > /etc/apt/sources.list.d/ros2-latest.list'
sudo apt update
sudo apt install ros-humble-desktop
Instalação do PX4
bash
Copiar
Editar
git clone https://github.com/PX4/PX4-Autopilot.git --recursive
cd PX4-Autopilot
bash ./Tools/setup/ubuntu.sh
cd PX4-Autopilot
make px4_sitl
🧱 Configuração do Workspace ROS 2
bash
Copiar
Editar
mkdir -p ~/ros2_ws/src
cd ~/ros2_ws/src
git clone https://github.com/PX4/px4_ros_com.git
cd ..
colcon build
source install/local_setup.bash
▶️ Executando o Código de Exemplo
bash
Copiar
Editar
ros2 launch px4_ros_com sensor_combined_listener.launch.py
💡 Dica de Produtividade
Ferramentas de IA, como o ChatGPT, são ótimas para resolver problemas de instalação e erros de dependência. Basta copiar e colar o comando ou a mensagem de erro completa — você pode se surpreender com a precisão das respostas!

📎 Referências
PX4 Docs

ROS 2 Docs

css
Copiar
Editar

Se quiser, posso gerar esse arquivo em formato `.md` para você baixar diretamente. Deseja isso?