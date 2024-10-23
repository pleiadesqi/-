#include <graphics.h>
#include <conio.h>
#include <windows.h>  
#include <stdio.h>
#include <process.h>   //���ڵ���ϵͳ����
#include <dos.h>


#define BUTTON_X 200
#define BUTTON_Y 200
#define BUTTON_WIDTH 150
#define BUTTON_HEIGHT 50
// ���ư�ť
void drawButton(int x, int y, int width, int height, const TCHAR* text) {
    setfillcolor(LIGHTMAGENTA);
    setlinecolor(BLACK);
    solidrectangle(x, y, x + width, y + height);

    settextcolor(LIGHTMAGENTA);
    settextstyle(20, 0, _T("����"));
    int textWidth = textwidth(text);
    int textHeight = textheight(text);
    outtextxy(x + (width - textWidth) / 2, y + (height - textHeight) / 2, text);
}


// ���������Ƿ��ڰ�ť������
bool isMouseInButton(int mouseX, int mouseY, int x, int y, int width, int height) {
    return (mouseX >= x && mouseX <= x + width && mouseY >= y && mouseY <= y + height);
}


int main() {
    // ��ʼ��ͼ��ģʽ
    initgraph(640, 480);

    // ���ͼ�δ����Ƿ�ɹ���ʼ��
    if (initgraph(640, 480) == 0) {
        printf("��ʼ��ͼ�δ���ʧ�ܣ�\n");
        return 1;
    }

    // ��ȡ��ǰ���ھ��
    HWND hWnd = GetConsoleWindow();  // ��ȡ����̨���ھ��
    if (hWnd == NULL) {
        printf("��ȡ���ھ��ʧ�ܣ�\n");
        return 1;
    }

    // ���ô��ڱ���
    LPCTSTR windowTitle = _T("�Զ�վ�����ļ�����ϵͳ");  
    SetWindowText(hWnd, windowTitle);

    // �����������ɫ
    settextcolor(LIGHTMAGENTA);
    setbkcolor(BLACK);

    // ����������ʽ
    settextstyle(30, 0, _T("����"));

    // ��ȡ��Ļ����λ��
    int x = getmaxx() / 2;
    int y = getmaxy() / 5;  // ����Ļ�Ϸ���ʾ

    // �����ı��Ŀ�Ⱥ͸߶�
    const TCHAR* welcomeMessage = _T("��ӭ�����Զ�վ�����ļ�����ϵͳ");
    int textWidth = textwidth(welcomeMessage);
    int textHeight = textheight(welcomeMessage);

    // ��ʾ��ӭ��Ϣ
    outtextxy(x - textWidth / 2, y - textHeight / 2, welcomeMessage);

    // ���ư�ť
    drawButton(BUTTON_X, BUTTON_Y, BUTTON_WIDTH, BUTTON_HEIGHT, _T("�ļ�����"));

    // �ȴ��û������������

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

        // ��� ESC ��
        if (GetAsyncKeyState(VK_ESCAPE) & 0x8000) {
            break;
        }

        // �����������
        if (_kbhit()) {
            char key = _getch();
            if (key == 27) {  // ESC ���˳�
                break;
            }
        }

        // �򵥵���ʱ����ֹ CPU ռ�ù���
        Sleep(10);
    }


    // �ر�ͼ�δ���
    closegraph();

    return 0; 
}