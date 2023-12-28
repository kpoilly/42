#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Score points by scanning valuable fish faster than your opponent.
 **/

typedef struct s_creature
{
    int id;
    int x;
    int y;
    int vx;
    int vy;
} creature;

typedef struct s_player
{
    int                 id;
    int                 x;
    int                 y;
    int                 emergency;
    int                 battery;
    int                 light;
    vector<string>       radar;
    vector<creature>    visibles;
    vector<int>         wfs;
} player;

typedef struct s_creature_specs
{
    int id;
    int color;
    int type;
} creature_specs;


bool    already_scanned(int fish_id, vector<int> scanned)
{
    for (int j = 0; j < scanned.size(); j++)
    {
        if (fish_id == scanned.at(j))
            return true;
    }
    return false;
}

bool    bougetonuc(vector<int> mine, vector<int> scanned, vector<int> his, vector<int> ennemy_as)
{
    for (int j = 0; j < mine.size(); j++)
    {
        if ((already_scanned(mine.at(j), his) || !already_scanned(mine.at(j), ennemy_as)) && !already_scanned(mine.at(j), scanned))
            return true;
    }
    return false;
}

int     get_color(int id, vector<creature_specs> all)
{
    for (int i = 0; i < all.size(); i++)
    {
        if (all.at(i).id == id)
            return (all.at(i).color);
    }
    return (0);
}

bool    color_line(vector<int> waiting_for_scan, vector<creature_specs> all)
{
    for (int i = 0; i < waiting_for_scan.size(); i++)
    {
        int to_check = get_color(waiting_for_scan.at(i), all);
        int count = 0;
        for (int j = 0; j < waiting_for_scan.size(); j++)
        {
            if (get_color(waiting_for_scan.at(j), all) == to_check)
                count++;
            cerr<<to_string(count)<<endl;
        }
        if (count >= 3)
            return (true);
    }
    return (false);
}

int get_closest_drone(player drone, player drone2, creature fish)
{
    if (((fish.x >= drone.x - 1100 && fish.x <= drone.x + 1100) && drone.light == 0) ||
        ((fish.x >= drone.x - 2300 && fish.x <= drone.x + 2300) && drone.light == 1))
        {
        if (((fish.x >= drone2.x - 1100 && fish.x <= drone2.x + 1100) && drone2.light == 0) ||
        ((fish.x >= drone2.x - 2300 && fish.x <= drone2.x + 2300) && drone2.light == 1))
            return (-1);
        else
            return (drone.id);
        }
    if (((fish.x >= drone2.x - 1100 && fish.x <= drone2.x + 1100) && drone2.light == 0) ||
        ((fish.x >= drone2.x - 2300 && fish.x <= drone2.x + 2300) && drone2.light == 1))
            return (drone2.id);
}

int main()
{
    player drone;
    player drone2;
    vector<creature_specs> all;
    vector<creature> visible;
    vector<int> ennemy_wfs;
    vector<int> scanned;
    vector<int> ennemy_scanned;
    vector<int> test;
    vector<player> drones;
    drones.push_back(drone);
    drones.push_back(drone2);

    bool down = true;
    int creature_count;
    cin >> creature_count; cin.ignore();
    for (int i = 0; i < creature_count; i++) {
        creature_specs creature;
        cin >> creature.id >> creature.color >> creature.type; cin.ignore();
        all.push_back(creature);
    }
    bool up1 = false;
    bool up2 = false;
    int phase1 = 0;
    int phase2 = 0;
    bool target1 = false;
    bool target2 = false;
    bool tempo2 = false;
    int add1 = 0;
    int add2 = 0;
    int x_togo1 = drone.x;
    int y_togo1;
    int y_togo2;
    int x_togo2 = drone2.x;
    // game loop
    while (1) {
        int my_score;
        cin >> my_score; cin.ignore();
        int foe_score;
        cin >> foe_score; cin.ignore();
        int my_scan_count;
        cin >> my_scan_count; cin.ignore();
        for (int i = 0; i < my_scan_count; i++) {
            int creature_id;
            cin >> creature_id; cin.ignore();
            if (!already_scanned(creature_id, scanned))
                scanned.push_back(creature_id);
        }
        int foe_scan_count;
        cin >> foe_scan_count; cin.ignore();
        for (int i = 0; i < foe_scan_count; i++) {
            int creature_id;
            cin >> creature_id; cin.ignore();
            if (!already_scanned(creature_id, ennemy_scanned))
                ennemy_scanned.push_back(creature_id);
        }
        int my_drone_count;
        cin >> my_drone_count; cin.ignore();
        for (int i = 0; i < my_drone_count; i++) {
            if (i == 0){
                cin >> drone.id >> drone.x >> drone.y >> drone.emergency >> drone.battery; cin.ignore();}
            else{
                cin >> drone2.id >> drone2.x >> drone2.y >> drone2.emergency >> drone2.battery; cin.ignore();}
        }
        int foe_drone_count;
        cin >> foe_drone_count; cin.ignore();
        for (int i = 0; i < foe_drone_count; i++) {
            int drone_id;
            int drone_x;
            int drone_y;
            int emergency;
            int battery;
            cin >> drone_id >> drone_x >> drone_y >> emergency >> battery; cin.ignore();
        }
        int drone_scan_count;
        cin >> drone_scan_count; cin.ignore();
        drone.wfs.clear();
        drone2.wfs.clear();
        for (int i = 0; i < drone_scan_count; i++) {
            int drone_id;
            int creature_id;
            cin >> drone_id >> creature_id; cin.ignore();
            if (drone_id == drone.id)
                drone.wfs.push_back(creature_id);
            else if(drone_id == drone2.id)
                drone2.wfs.push_back(creature_id);
            else
                ennemy_wfs.push_back(creature_id);
        }
        int visible_creature_count;
        cin >> visible_creature_count; cin.ignore();
        drone.visibles.clear();
        drone2.visibles.clear();
        for (int i = 0; i < visible_creature_count; i++) {
            creature creature;
            cin >> creature.id >> creature.x >> creature.y >> creature.vx >> creature.vy; cin.ignore();
            int drone_id = get_closest_drone(drone, drone2, creature);
            if (drone_id == drone.id && creature.id >= 16)
                drone.visibles.push_back(creature);
            else if (drone_id == drone2.id && creature.id >= 16)
                drone2.visibles.push_back(creature);
            else if (drone_id == -1 && creature.id >= 16)
            {
                drone.visibles.push_back(creature);
                drone2.visibles.push_back(creature);
            }
        }
        int radar_blip_count;
        drone.radar.clear();
        cin >> radar_blip_count; cin.ignore();
        for (int i = 0; i < radar_blip_count; i++) {
            int   drone_id;
            int   fish_id;
            string  pos;
            cin >> drone_id >> fish_id >> pos; cin.ignore();
            if (drone_id == drone.id && fish_id >= 16)
                drone.radar.push_back(pos);
            else if (drone_id == drone2.id && fish_id >= 16)
                drone2.radar.push_back(pos);
        }

        string action = "MOVE";
        string msg1 = " 42Paris              ON TOP";
        string msg2 = " 42Paris              ON TOP";
        // string msg1 = " " + to_string(phase1);
        // string msg2 = " " + to_string(phase2);
        int light = 0;

        for (int i = 0; i < my_drone_count; i++) {

            // Write an action using cout. DON'T FORGET THE "<< endl"
            // To debug: cerr << "Debug messages..." << endl;    
            
            if (i == 0)
            {
                // Light
                if (drone.battery > 5 && drone.y > 2500)
                    drone.light = 1;
                else
                    drone.light = 0;

                int count1 = 0;
                if (!up1){
                    for (int i = 0; i < drone.visibles.size(); i++)
                    {
                        target1 = true;

                        if (!((drone.visibles.at(i).x >= drone.x - 300) && (drone.visibles.at(i).x <= drone.x + 300)))
                        {
                            if (phase1 == 1 || phase1 == 3)
                                y_togo1 -= 300;
                            else if (phase1 == 0 || phase1 == 2)
                                y_togo1 += 300;
                            else
                                y_togo1 = drone.y;
                        }
                        else
                        {
                            if (drone.y < drone.visibles.at(i).y && drone.visibles.at(i).vy < 0)
                                y_togo1 += drone.visibles.at(i).vy - 300; //-600
                            else if (drone.y > drone.visibles.at(i).y && drone.visibles.at(i).vy > 0)
                                y_togo1 += drone2.visibles.at(i).vy + 300; //+600
                            else
                                y_togo1 = drone.y;
                        }
                        
                        if (drone.x < drone.visibles.at(i).x && drone.visibles.at(i).vx <= 0)
                            x_togo1 += drone.visibles.at(i).vx - 300; //-600
                        else if (drone.x > drone.visibles.at(i).x && drone.visibles.at(i).vx >= 0)
                            x_togo1 += drone.visibles.at(i).vx + 300; //+600
                        else
                            x_togo1 = drone.x;

                        drone.light = 0;
                        msg1 = " AAAAAAH";
                        count1++;
                    }
                    if (count1 == 0)
                    {
                        if (target1)
                        {
                            drone.light = 1;
                            msg1 = " g eu cho";
                            target1 = false;
                            if (drone.y >= 7500)
                                phase1 = 1;
                        }
                    }
                }

                // Remonter a la surface
                if (drone.y <= 6000 && target1 && drone.wfs.size() > 0)
                    up1 = true;
                if (up1)
                {
                    y_togo1 = 0;
                    if (drone.y <= 450)
                    {
                        phase1 = 0;
                        up1 = false;
                    }
                }

                //Phases de rotation
                if (phase1 == 0 && !up1 && !target1)
                {
                    x_togo1 = 1700;
                    y_togo1 = 9000;
                    if (drone.y >= 8500 )
                        phase1 = 1;
                }
                if (phase1 == 1 && !up1 && !target1)
                {
                    x_togo1 = 5000;
                    y_togo1 = 0;
                    if (drone.y <= 450)
                        phase1 = 2;
                }
                if (phase1 == 2 && !up1 && !target1)
                {
                    y_togo1 = 9500;
                    if (drone.y >= 9100)
                        phase1 = 3;
                }
                if (phase1 == 3 && !up1 && !target1)
                {
                    y_togo1 = 0;
                    if (drone.y <= 450)
                        phase1 = 0;
                }

                int countl1 = 0;
                int countd1 = 0;
                int countu1 = 0;
                for (int i = 0; i < drone.radar.size(); i++)
                {
                    if (drone.radar.at(i) == "BL" || drone.radar.at(i) == "TL")
                        countl1++;
                    if (drone.radar.at(i) == "BR" || drone.radar.at(i) == "TR")
                        countd1++;
                    if (drone.radar.at(i) == "TL" || drone.radar.at(i) == "TR")
                        countu1++;
                }

                if (countl1 > countd1 || (countl1 == countd1 && drone.x <= 5000))
                    add1 += 100;
                else if (countl1 < countd1 || (countl1 == countd1 && drone.x > 5000))
                    add1 -= 100;
                if (!countu1 && y_togo1 < drone.y)
                    add1 = 0;

                x_togo1 += add1;

                // Aller plus vite sur les bords
                if (drone.y == 9999 || y_togo1 >= 9999)
                    y_togo1 = 9998;
                if (drone.x == 0 || x_togo1 <= 0)
                    x_togo1 = 1;
                else if (drone.x == 9999 || y_togo1 >= 9999)
                    x_togo1 = 9998;

                cout << action + " " + to_string(x_togo1) + " " + to_string(y_togo1) + " " + to_string(drone.light) + msg1<<endl;

            }
            else
            {
                // Light
                if (drone2.battery > 5 && drone2.y > 2500 && drone2.y < 7500)
                    drone2.light = 1;
                else
                    drone2.light = 0;

                int count2 = 0;

                if (!up2){

                    //"""Esquive""" des mechants visibles
                    for (int i = 0; i < drone2.visibles.size(); i++)
                    {
                        target2 = true;

                        if (!((drone2.visibles.at(i).x >= drone2.x - 300) && (drone2.visibles.at(i).x <= drone2.x + 300)))
                        {
                            if (phase2 == 1 || phase2 == 3)
                                y_togo2 -= 300;
                            else if (phase2 == 0 || phase2 == 2)
                                y_togo2 += 300;
                            else
                                y_togo2 = drone2.y;
                        }
                        else
                        {
                            if (drone2.y < drone2.visibles.at(i).y && drone2.visibles.at(i).vy < 0)
                                y_togo2 += drone2.visibles.at(i).vy; //-600
                            else if (drone2.y > drone2.visibles.at(i).y && drone2.visibles.at(i).vy > 0)
                                y_togo2 += drone2.visibles.at(i).vy; //+600
                            else
                                y_togo2 = drone2.y;
                        }
                        
                        if (drone2.x < drone2.visibles.at(i).x && drone2.visibles.at(i).vx <= 0)
                                x_togo2 += drone2.visibles.at(i).vx; //-600
                        else if (drone2.x > drone2.visibles.at(i).x && drone2.visibles.at(i).vx >= 0)
                                x_togo2 += drone2.visibles.at(i).vx; //+600
                        else
                                x_togo2 = drone2.x;

                        // if (!((drone2.visibles.at(i).y >= drone2.y - 250) && (drone2.visibles.at(i).y <= drone2.y + 250)))
                        // {
                        //     if (drone2.x <= 5000)
                        //         x_togo2 += drone2.visibles.at(i).vx + 800;
                        //     else
                        //         x_togo2 += drone2.visibles.at(i).vx - 800;
                        // }
                        // else if (drone2.visibles.at(i).x > drone2.x && drone2.visibles.at(i).vx <= 0)
                        //     x_togo2 += drone2.visibles.at(i).vx - 800;
                        // else if (drone2.visibles.at(i).x < drone2.x && drone2.visibles.at(i).vx >= 0)
                        //     x_togo2 += drone2.visibles.at(i).vx + 800;
                        // else
                        //     x_togo2 = drone2.x;
                        drone2.light = 0;
                        msg2 = " AAAAAAH";
                        count2++;
                    }
                    if (count2 == 0)
                    {
                        if (target2)
                        {
                            if (drone2.y > 2500 && drone2.y < 7500)
                                drone2.light = 1;
                            msg2 = " g eu cho";
                            target2 = false;
                            if (drone2.y >= 7500)
                                phase2 = 1;
                        }
                    }
                }

                // Remonter a la surface
                if (drone2.y <= 6000 && target2 && drone2.wfs.size() > 2)
                    up2 = true;
                if (up2)
                {
                    y_togo2 = 0;
                    if (drone2.y <= 450)
                    {
                        phase2 = 0;
                        up2 = false;
                    }
                }

                //Phases de rotation
                if (phase2 == 0 && !up2 && !target2)
                {   
                    x_togo2 = 8300;
                    y_togo2 = 9000;
                    if (drone2.y >= 8500)
                        phase2 = 1;
                }
                if (phase2 == 1 && !up2 && !target2)
                {
                    x_togo2 = 5000;
                    y_togo2 = 0;
                    if (drone2.y <= 450)
                        phase2 = 2;
                }
                if (phase2 == 2 && !up2 && !target2)
                {
                    y_togo2 = 9500;
                    if (drone2.y >= 9100)
                        phase2 = 3;
                }
                if (phase2 == 3 && !up2 && !target2)
                {
                    y_togo2 = 0;
                    if (drone2.y <= 450)
                        phase2 = 0;
                }
                

                //Fait des mouvements plus ou moins random pour essayer de contourner les mechants non visibles
                if (!target1)
                {    int countl2 = 0;
                    int countd2 = 0;
                    int countu2 = 0;
                    for (int i = 0; i < drone.radar.size(); i++)
                    {
                        if (drone.radar.at(i) == "BL" || drone.radar.at(i) == "TL")
                            countl2++;
                        if (drone.radar.at(i) == "BR" || drone.radar.at(i) == "TR")
                            countd2++;
                        if (drone.radar.at(i) == "TL" || drone.radar.at(i) == "TR")
                            countu2++;
                    }

                    if (countl2 > countd2 || (countl2 == countd2 && drone2.x <= 5000))
                        {add2 += 100;
                        cerr << ">>" << endl;}
                    else if (countl2 < countd2 || (countl2 == countd2 && drone2.x > 5000))
                        {add2 -= 100;
                        cerr << "<<" << endl;}
                    if (!countu2 && y_togo2 < drone2.y)
                        add2 = 0;

                    x_togo2 += add2;}

                // Aller plus vite sur les bords
                if (drone2.y == 9999 || y_togo2 >= 9999)
                    y_togo2 = 9998;
                if (drone2.x == 0 || x_togo2 <= 0)
                    x_togo2 = 1;
                else if (drone2.x == 9999 || x_togo2 >= 9999)
                    x_togo2 = 9998;

                cout << action + " " + to_string(x_togo2) + " " + to_string(y_togo2) + " " + to_string(drone2.light) + msg2<<endl;
            }    
        }
    }
}