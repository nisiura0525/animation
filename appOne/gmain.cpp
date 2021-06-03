
#define _EX
#ifdef _EX

#include"libOne.h"
void gmain() {
    window(1920, 1080, full);
    //�����p�f�[�^
    struct EXP {
        float px, py, angle, scale;
        int counter= -1, interval;
    };
    const int numEx = 30;
    struct EXP e[numEx];
    //�摜�̃f�[�^
    const int numImgs = 60;
    int imgs[numImgs];
    for (int i = 0; i < numImgs; i++) {
        char framename[50];           //%02d�͍Œ�2���ŕ\�����邱��
        sprintf_s(framename, "assets\\explosion\\a%02d.png", i);
        imgs[i] = loadImage(framename);
    }
    int Excon = 0;
    int Exinterval = 10;
    while (notQuit) {
        clear(3, 252, 227);
        ++Excon %= Exinterval;
        if (Excon == 0) {
            for (int i = 0; i < numEx;i++) {
                if (e[i].counter == -1) {
                    e[i].px = random(width / 2-200,width/2+200);
                    e[i].py = random(height / 2-100,height/2+100);
                    e[i].angle = random(6.28f);
                    e[i].scale = random(5,10);
                    e[i].interval = random(1,3);
                    e[i].counter = 0;
                    i = numEx;
                }
            }

        }
        for (int i = 0; i < numEx;i++) {
            if (e[i].counter >= 0) {
                e[i].counter++;
                if (e[i].counter >= numImgs * e[i].interval) {
                    e[i].counter = -1;
                }
            }
        }
        for (int i = 0; i < numEx;i++) {
            if (e[i].counter >= 0) {
                rectMode(CENTER);//0�`59��1�D3�ł��摜�i���o�[�Ɋ��蓖�Ă�
                int no = e[i].counter / e[i].interval;
                image(imgs[no], e[i].px, e[i].py, e[i].angle, e[i].scale);
            }
        }
        
    }
}
#endif

/*
#define _EX
#ifdef _EX

#include"libOne.h"
void gmain() {
    window(1920, 1080, full);
        //�����p�f�[�^
    struct EXPLOSION {
        float px, py, angle, scale;
        int interval, counter = 1;
    };
    const int numEx = 30;
    struct EXPLOSION e[numEx];
    //�摜�f�[�^
    const int numImgs = 60;
    int imgs[numImgs];
    for (int i = 0;i < numImgs;i++) {
        char filename[50];//��������L�����鐔���u�v�̒��Ɏw�肷��
        sprintf_s(filename, "assets\\explosion\\a%02d.png", i);
        imgs[i] = loadImage(filename);
    }
    int Triggercnt = 0;
    int TriggerInterval = 3;
   
    while (notQuit) {
            clear(3, 252, 227);
        //�����g���K�[
        ++Triggercnt %= TriggerInterval;
        if (Triggercnt == 0) {
            for (int i = 0;i < numEx;i++) {
                if (e[i].counter == -1) {
                    e[i].px = random(width / 2 - 400, width / 2 + 400);
                    e[i].py = random(height / 2 - 200, height / 2 + 200);
                    e[i].angle = random(6.28f);//6.28���W�A����360%
                    e[i].scale = random(10, 20);
                    e[i].interval = random(1,3);
                    e[i].counter = 0;
                    i = numEx;
                }
            }
        }
        //�����i�s
        for (int i = 0;i < numEx;i++) {
            if (e[i].counter >= 0) {
                e[i].counter++;
                //�����I��
                if (e[i].counter >= e[i].interval * numImgs) {
                    e[i].counter = -1;
                }
            }
        }
        //�`��
        for (int i = 0;i < numEx;i++) {
            if (e[i].counter >= 0) {
                rectMode(CENTER);
                int no = e[i].counter / e[i].interval;
                image(imgs[no], e[i].px, e[i].py, e[i].angle, e[i].scale);
            }
        }

    }
}
#endif
*/

/*
#define _EX
#ifdef _EX

#include"libOne.h"
void gmain() {
    window(1920, 1080, full);
    float px = width / 2, py = height / 2, angle = 0, scale = 1, vx = 8;
    int conster = 0, interval = 8;
    const int num = 8;
    int img[num];
    for (int i = 0;i < num; i++) {
        char name  [100];
        sprintf_s(name,"assets\\lady\\a%d.png",i);
        img[i] = loadImage(name);
    }
    while (notQuit) {
        for (int i = 0;i < num; i++) {
            if (isPress(KEY_D)) {
                char name[100];
                sprintf_s(name, "assets\\lady\\b%d.png", i);
            }
        }
        clear(3, 252, 227);
        ++conster %= num * interval;
        int no = conster / interval;
        rectMode(CENTER);
        if (isPress(KEY_A)) {
            px += -vx;
        }

        if (isPress(KEY_D)) {
            px += vx;
        }
            image(img[no], px, py, angle, scale);
    }
       
}
#endif
*/
/*
#define _EX
#ifdef _EX

#include"libOne.h"
void gmain() {
    window(1920, 1080, full);
    const int num = 8;
    int img[num];
    float px = width / 2, py = height / 2, angle = 0, scale = 1;
    int conster = 0,intervale = 8;
    for (int i = 0;i < num;i++) {
        char name[50];
        sprintf_s(name,"assets\\lady\\a%d.png", i);
        img[i] = loadImage(name);
    }
    while (notQuit) {
        clear(3, 252, 277);
        ++conster %= num*intervale;
        int no = conster/intervale;
        if (isPress(KEY_A)) {
            px += -10;
        }
        if (isPress(KEY_D)) {
            px += 10;
        }
        rectMode(CENTER);
        image(img[no], px, py, angle, scale);
    }
}
#endif 
*/
/*
#define _EX
#ifdef _EX

#include"libOne.h"
void gmain() {
    window(1920, 1080, full);
    struct CHARA {
        float px, py, angle, scale;
    };
    const int num = 8;
    int imgs[num];
    int counter = 0, interval = 1;
    for (int i = 0;i < num; i++) {
        char name[50];
        sprintf_s(name, "assets\\lady\\a%d.png", i);
        imgs[i] = loadImage(name);
    }
    
    struct CHARA c;
    c.px = width / 2;
    c.py = height / 2;
    c.angle = 0;
    c.scale = 1;
    while (notQuit) {
        ++counter %= num*interval;
        int no = counter/interval;
        clear(3, 252, 277);
        
            rectMode(CENTER);
            image(imgs[no], c.px, c.py, c.angle, c.scale);
        

    }
}

#endif
*/

















#ifdef _SAMPLE1
#include"libOne.h"
void gmain() {
    window(1920, 1080, full);
    //�L�����f�[�^
    float px = width / 2, py = height / 2, angle = 0, scale = 1.0f;
    int counter = -1, interval = 8;
    //�摜�ԍ��z��f�[�^
    const int numImgs = 8;
    int imgs[numImgs];
    //�摜�ǂݍ���
    for (int i = 0; i < numImgs; i++) {
        char filename[32];
        sprintf_s(filename, "assets\\lady\\a%d.png", i);
        imgs[i] = loadImage(filename);
    }
    //���C�����[�v
    ShowCursor(false);
    while (notQuit) {
        int maxFrame = interval * numImgs;
        ++counter %= maxFrame;
        int no = counter / interval;
        //�`��
        clear(200, 160, 200);
        rectMode(CENTER);
        image(imgs[no], px, py, angle, scale);
    }
    ShowCursor(true);
}
#endif

#ifdef _SAMPLE2
#include"libOne.h"
void gmain() {
    window(1920, 1080, full);
    //�����f�[�^
    struct EXPLOSION {
        float px, py, angle, scale;
        int interval, counter = -1;
    };
    const int numExplosions = 30;
    struct EXPLOSION e[numExplosions];
    int triggerCnt = 0;
    int triggerInterval = 5;
    //�摜�f�[�^
    const int numImgs = 60;
    int imgs[numImgs];
    for (int i = 0; i < numImgs; i++) {
        char filename[32];
        sprintf_s(filename, "assets\\explosion\\a%02d.png", i);
        imgs[i] = loadImage(filename);
    }
    ShowCursor(false);
    while (notQuit) {
        //�����J�n
        ++triggerCnt %= triggerInterval;
        if (triggerCnt == 0) {
            for (int i = 0; i < numExplosions; i++) {
                if (e[i].counter == -1) {
                    e[i].px = random(width / 2 - 150, width / 2 + 150);
                    e[i].py = random(height / 2 - 100, height / 2 + 100);
                    e[i].angle = random(3.14f * 2);
                    e[i].scale = random(5.0f, 10.0f);
                    e[i].interval = random(1, 3);
                    e[i].counter = 0;
                    i = numExplosions;
                }
            }
        }
        //�����i�s
        for (int i = 0; i < numExplosions; i++) {
            if (e[i].counter >= 0) {
                ++e[i].counter;
                //�����I��
                if (e[i].counter >= e[i].interval * numImgs) {
                    e[i].counter = -1;
                }
            }
        }
        //�`��
        clear(60, 120, 240);
        rectMode(CENTER);
        for (int i = 0; i < numExplosions; i++) {
            if (e[i].counter >= 0) {
                int no = e[i].counter / e[i].interval;
                image(imgs[no], e[i].px, e[i].py, e[i].angle, e[i].scale);
            }
        }
    }
    ShowCursor(true);
}
#endif