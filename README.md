# CADProject  
Hi 这是我写的第一个README.md。本项目是一个基于半边数据结构的CAD底层拓扑结构的搭建。我们以半边（**HalfEdge**）为中心，向下延伸到点（**Vertex**），向上延伸到边（**Edge**）、环（**Loop**）、面（**Face**）、体（**Solid**）；同时，点、边和面又对应到各自几何上的**Point**、**Curve**和**Surface**。本项目中保留了**Curve**和**Surface**的接口，从原理上说是可以绘制更复杂的曲线，但我还没有打算去实现它:D所以目前看到的实例都是由直线段构成的。<br><br>
在完成基本拓扑结构的定义后，我们在这些拓扑结构基础上实现了五种欧拉操作（**mev**/**mef**/**mvsf**/**kemr**/**kfmrh**）。只需要向程序发送顶点坐标和**正确且有序的**欧拉操作数，就能实现三维模型的构建。一定程度上说这就是一个CAD软件的雏形了。<br><br>
基于欧拉操作，我们还实现了线性的扫掠，即由面从一个向量的起点扫掠到终点，其路径上所经过的点共同构成一个2.5维的体，就像SolidWorks中的拉伸凸台/基体操作一样。此后用户若要构建简单的三维形体，就可以仅通过一个面和一个向量来定义，大大方便了CAD操作。<br><br>
当然，从原理上，任意**正确且有序的**欧拉操作数和顶点坐标都可以在本程序上构建出合法的三维模型；不过，由于**正确且有序的**欧拉操作数输入比较麻烦（其实主要是可能不正确！），所以我们给出了两个实例来演示该程序的功能。其中，第一个实例是是由欧拉操作逐步建立的带通孔的立方体；第二个则是由欧拉操作建立底面后，用线性扫掠操作形成的双孔三棱柱。它们的具体数据写在**Example.cpp**中，你可以尝试修改它们来绘制新的三维模型。<br><br>
最后，我们在**Draw.cpp**中为这两个实例进行了简单的实时渲染（其实写渲染才是最头疼的Orz（对第一次在电脑上画画的我来说））。你可以用键盘上的w/a/s/d来调整视点，用鼠标滚轮控制放大/缩小。大概看起来就像这样：<br><br>
要运行这个项目，首先你要下载它，其次你应该确保安装了glut.h库。然后你应该就可以使用Visual Studio打开**CADProject.sln**文件生成项目并运行啦；或者也可以用别的IDE来编译全部项目，最后运行**main.cpp**查看结果。如果嫌麻烦，也可以直接打开项目中的**Show.exe**来免编译查看实例运行结果。<br><br>
有任何问题，欢迎通过llzju@zju.edu.cn联系我哦。<br><br>
## *Reference*<br>
*带通孔多边形的绘制：http://www.songho.ca/opengl/gl_tessellation.html*<br>
*绘制中的键盘交互：https://www.bbsmax.com/A/gAJGAQGgdZ/*<br>
