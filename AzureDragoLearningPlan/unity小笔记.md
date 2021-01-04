#### 快捷键
- q w e r t y 对应变换工具；f聚焦 
- ALT + 左键，展开对象的所有继承
- unity关联VS： 下载vs，工具 >> 获取工具和功能 >> 使用unity的游戏开发勾选。
- unity导入资源包：unity里：window >>Asset store >> 添加到账户>>打开unity导入   或者直接  window>> package manager

#### 冷知识
- Skinned Mesh Renderer 是一种特殊类型的 Mesh Renderer，可让网格根据模型所有骨骼的位置和旋转来改变形状。这些骨骼是模型的子游戏对象 — JohnLemon 的骨骼是 Root 游戏对象的所有子项
- 根运动。 **Update和FixedUpdate** 。Animator 在 Update 中移动角色，而 Rigidbody 同时在 Fixed Update 中移动角色。前者是
- GetComponent<Animator>()为monoBehaviour已经实现的泛型方法，所以使用<>，其中放入的为类型，表示获得Animator组件。
- draw call指将内存数据送入显存渲染的过程；qte指quick time event指一种游戏玩法，指定时间狂按某键触发剧情；截帧指获取显存中的数据，如opengl的缓存数据，顶点、uv等信息。

#### C#编写
- 函数参数使用out主要是因为，函数return一般用布尔类型，out为真正要修改的值。
- 反射机制：unity中某个对象附加脚本文件后能显示公开成员，就是因为反射机制。反射机制的本质是解析了代码文本文件，获得了该类的内容，C#会提供相关的函数接口调用获得类的内容。

#### unity的单例模式（泛型singleton）
- 不需要用到unity的生命周期，定义属性访问器Instance就可以
- 需要用到unity生命周期，需要继承MonoBehaviour，需要一个GameObject用来挂载所有相关单例，如GameManager、BattleManager。场景切换是否销毁该单例，使用一个bool值做标志。

#### UGUI--anchors为了做UI适应
- anchors聚集时的作用是：该UI对象中Rect Transform显示的位置为：它的轴心点相对于anchors的位置。可以控制某条边位置改变而不改变这个位置。
- anchors分开时的作用是：控制子物体和父物体的位置相对固定。
