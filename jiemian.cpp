#include <graphics.h>
#include <conio.h>
#include <windows.h>  
#include <stdio.h>
#include <process.h>   //用于调用系统命令
#include <dos.h>


#define BUTTON_X 200
#define BUTTON_Y 200
#define BUTTON_WIDTH 150
#define BUTTON_HEIGHT 50
// 绘制按钮
void drawButton(int x, int y, int width, int height, const TCHAR* text) {
    setfillcolor(LIGHTMAGENTA);
    setlinecolor(BLACK);
    solidrectangle(x, y, x + width, y + height);

    settextcolor(LIGHTMAGENTA);
    settextstyle(20, 0, _T("宋体"));
    int textWidth = textwidth(text);
    int textHeight = textheight(text);
    outtextxy(x + (width - textWidth) / 2, y + (height - textHeight) / 2, text);
}


// 检查鼠标点击是否在按钮区域内
bool isMouseInButton(int mouseX, int mouseY, int x, int y, int width, int height) {
    return (mouseX >= x && mouseX <= x + width && mouseY >= y && mouseY <= y + height);
}


int main() {
    // 初始化图形模式
    initgraph(640, 480);

    // 检查图形窗口是否成功初始化
    if (initgraph(640, 480) == 0) {
        printf("初始化图形窗口失败！\n");
        return 1;
    }

    // 获取当前窗口句柄
    HWND hWnd = GetConsoleWindow();  // 获取控制台窗口句柄
    if (hWnd == NULL) {
        printf("获取窗口句柄失败！\n");
        return 1;
    }

    // 设置窗口标题
    LPCTSTR windowTitle = _T("自动站数据文件处理系统");  
    SetWindowText(hWnd, windowTitle);

    // 设置字体和颜色
    settextcolor(LIGHTMAGENTA);
    setbkcolor(BLACK);

    // 设置字体样式
    settextstyle(30, 0, _T("宋体"));

    // 获取屏幕中心位置
    int x = getmaxx() / 2;
    int y = getmaxy() / 5;  // 在屏幕上方显示

    // 计算文本的宽度和高度
    const TCHAR* welcomeMessage = _T("欢迎进入自动站数据文件处理系统");
    int textWidth = textwidth(welcomeMessage);
    int textHeight = textheight(welcomeMessage);

    // 显示欢迎消息
    outtextxy(x - textWidth / 2, y - textHeight / 2, welcomeMessage);

    // 绘制按钮
    drawButton(BUTTON_X, BUTTON_Y, BUTTON_WIDTH, BUTTON_HEIGHT, _T("文件分类"));

    // 等待用户按键或鼠标点击

    ExMessage msg;
    while (true) {
        if (peekmessage(&msg, EM_MOUSE))
        {
            switch (msg.message)
            {
                case WM_LBUTTONDOWN:
                    if (msg.x >= 200 && msg.x <= 200 + 150 && msg.y >= 50 && msg.y <= 200 + 50)
                    {
                        system("start D:\\programming\\code\\2024\\wenjian_fenlei.bat");
                        Sleep(200);
                    }
                    break;
            }

        }

        // 检测 ESC 键
        if (GetAsyncKeyState(VK_ESCAPE) & 0x8000) {
            break;
        }

        // 检测其他按键
        if (_kbhit()) {
            char key = _getch();
            if (key == 27) {  // ESC 键退出
                break;
            }
        }

        // 简单的延时，防止 CPU 占用过高
        Sleep(10);
    }


    // 关闭图形窗口
    closegraph();

    return 0; 
}