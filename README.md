# 文件说明
- **menuChooser.h** 键盘交互式的菜单选择头文件
- **DPLL.hpp** 优化前的基于DPLL算法的SAT求解器
- **DPLL_optimized.hpp** 优化后的基于DPLL算法的SAT求解器
- **sudoku.hpp** 数独处理部分
- **main.cpp** 主程序，包含SAT求解与数独游玩功能
- **sudoku_main.cpp** 数独主程序，仅包含数独游玩功能

# 使用说明
- 打开main.exe或sudoku_main.exe启动程序，建议最大化窗口获得更佳体验
- 所有选择界面下，按下方向键切换选项，回车键确定
- CNF文件读取功能下，open directory为读取指定目录下所有匹配.cnf后缀的文件，open file为读取指定文件。文件地址可用相对或绝对地址。
- 游玩数独时，按下方向键移动选框，按下1-9数字键填入或修改数字，按下回车结束游戏。正确数字为绿色，错误数字为红色。

