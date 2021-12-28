# Hover-entire-row-of-QTableWidget
Hover entire row/column of QTableWidget, support qss.


![image](https://github.com/lowbees/images/blob/master/5.gif)
![image](https://github.com/lowbees/images/blob/master/6.gif)


## 2019-2-1 更新
由于之前的问题太多，已经丢弃之前的写法，现在更换一种更合理的方法

## 2021/12/28 更新
在lowbees的基础上添加了滚轮事件，鼠标移出事件，使组件完全与原生效果一致

将适用组件从qtableview改为qtablewidget，因为我项目用的是后者。

使用方法：
1、把ui设计界面的qtablewidget提升为项目中的myHoverTableWidget

2、样式表中设置鼠标悬停样式
QTableView::item:hover {
    background-color: rgba(200,200,220,255);
}   

3、代码中设置代理

mytablewidget->setItemDelegate(new StyledItemDelegate);

成功！

