Aquí tienes el contenido para el archivo `README.md` de tu repositorio:

# **Proyecto de Selección de Esferas en 3D con openFrameworks**

## **Descripción General**
Este proyecto utiliza **openFrameworks**, un framework de código abierto basado en `C++` para aplicaciones multimedia, gráficos y arte digital interactivo. openFrameworks proporciona herramientas eficientes para la manipulación de gráficos en 2D y 3D, facilitando la creación de experiencias interactivas.

## **Objetivo del Proyecto**
El objetivo de este proyecto es implementar una cuadrícula de esferas en un espacio tridimensional, permitiendo la **interacción del usuario** a través del mouse. Se pueden seleccionar esferas individuales, visualizar su posición en pantalla y cambiar su color sin afectar a las demás.

## **Características Implementadas**
✅ Generación de una cuadrícula de esferas en 3D.  
✅ Navegación interactiva con la cámara (`ofEasyCam`).  
✅ Selección de esferas con detección de intersección de rayos (`ray casting`).  
✅ Cambio de color de la esfera seleccionada sin afectar a las demás.  
✅ Visualización de la posición de la esfera seleccionada en pantalla.

## **Resultados Esperados**
Al ejecutar la aplicación, se presenta un entorno 3D con varias esferas dispuestas en el espacio. El usuario puede navegar libremente con la cámara y, al hacer clic en una esfera, su color cambia aleatoriamente y su posición se muestra en la pantalla. Esta funcionalidad es útil para aplicaciones interactivas en gráficos 3D, videojuegos y visualización de datos.

## **Requisitos**
- openFrameworks (versión recomendada: 0.11.2 o superior)
- C++11 o superior
- Entorno de desarrollo compatible (Xcode, Visual Studio, Code::Blocks)

## **Cómo Ejecutar el Proyecto**
1. **Clona el repositorio**  
   ```sh
   git clone <URL-del-repositorio>
   ```
2. **Abre el proyecto en openFrameworks**
   - Para Xcode: Abre el archivo `.xcodeproj`
   - Para Visual Studio: Abre el archivo `.sln`
   - Para Code::Blocks: Abre el archivo `.cbp`
3. **Compila y ejecuta la aplicación**
   - En Xcode: `Cmd + R`
   - En Visual Studio: `F5`
   - En Code::Blocks: `Ctrl + F9`

## **Licencia**
Este proyecto se distribuye bajo la licencia MIT.

---