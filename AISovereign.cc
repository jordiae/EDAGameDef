#include "Player.hh"


/**
 * Write the name of your player and save this file
 * with the same name and .cc extension.
 */
#define PLAYER_NAME Sovereign


struct PLAYER_NAME : public Player {

  /**
   * Factory: returns a new instance of this class.
   * Do not modify this function.
   */
  static Player* factory () {
    return new PLAYER_NAME;
  }

  inline bool extra_haunted(Pos pos) {
    Cell c = cell(pos);
    if (c.haunted) {
      return true;
    }
    for (int i = 0; i < 8; i++) {
      Pos pos_aux = pos+farmer_movements[i];
      c = cell(pos_aux);
      if (c.haunted)
        return true;
    }
    return false;
  }

  inline int self_haunted(Pos pos) {
    int damage = 0;
    for (int i = 0; i < 8; i++) {
      Cell c = cell(pos+farmer_movements[i]);
      if (c.id != -1) {
        Unit u = unit(c.id);
        if (u.player == 0 and u.type != Witch) {
          if (u.type == Farmer)
            damage += 1;
          else if (u.type == Knight)
            damage += 2;
        }
      }
    }
    Cell c = cell(pos+Left+Left);
    Unit u;
    if (c.id != -1) {
      u = unit (c.id);
      if (u.player == 0 and u.type != Witch) {
        if (u.type == Farmer)
          damage += 1;
        else if (u.type == Knight)
          damage += 2;
      }
    }
    c = cell(pos+Top+Top);
    if (c.id != -1) {
      u = unit (c.id);
      if (u.player == 0 and u.type != Witch) {
        if (u.type == Farmer)
          damage += 1;
        else if (u.type == Knight)
          damage += 2;
      }
    }
    c = cell(pos+Right+Right);
    if (c.id != -1) {
      u = unit (c.id);
      if (u.player == 0 and u.type != Witch) {
        if (u.type == Farmer)
          damage += 1;
        else if (u.type == Knight)
          damage += 2;
      }
    }
    c = cell(pos+Bottom+Bottom);
    if (c.id != -1) {
      u = unit (c.id);
      if (u.player == 0 and u.type != Witch) {
        if (u.type == Farmer)
          damage += 1;
        else if (u.type == Knight)
          damage += 2;
      }
    }
    return damage;
  }

    inline int other_haunted(Pos pos) {
    int damage = 0;
    for (int i = 0; i < 8; i++) {
      Cell c = cell(pos+farmer_movements[i]);
      if (c.id != -1) {
        Unit u = unit(c.id);
        if (u.player != 0 and u.type != Witch) {
          if (u.type == Farmer)
            damage += 1;
          else if (u.type == Knight)
            damage += 2;
        }
      }
    }
    Cell c = cell(pos+Left+Left);
    Unit u;
    if (c.id != -1) {
      u = unit (c.id);
      if (u.player != 0 and u.type != Witch) {
        if (u.type == Farmer)
          damage += 1;
        else if (u.type == Knight)
          damage += 2;
      }
    }
    c = cell(pos+Top+Top);
    if (c.id != -1) {
      u = unit (c.id);
      if (u.player != 0 and u.type != Witch) {
        if (u.type == Farmer)
          damage += 1;
        else if (u.type == Knight)
          damage += 2;
      }
    }
    c = cell(pos+Right+Right);
    if (c.id != -1) {
      u = unit (c.id);
      if (u.player != 0 and u.type != Witch) {
        if (u.type == Farmer)
          damage += 1;
        else if (u.type == Knight)
          damage += 2;
      }
    }
    c = cell(pos+Bottom+Bottom);
    if (c.id != -1) {
      u = unit (c.id);
      if (u.player != 0 and u.type != Witch) {
        if (u.type == Farmer)
          damage += 1;
        else if (u.type == Knight)
          damage += 2;
      }
    }
    return damage;
  }
/*
  inline bool self_haunted(Pos pos) {
    for (int i = 0; i < 8; i++) {
      Cell c = cell(pos+farmer_movements[i]);
      Unit u = unit(c.id);
      if (u.id != -1 and u.player == 0 and u.type != Witch)
        return true;
    }
    Cell c = cell(pos+Left+Left);
    Unit u = unit (c.id);
    if (u.id != -1 and u.player == 0 and u.type != Witch)
      return true;
    c = cell(pos+Top+Top);
    u = unit (c.id);
    if (u.id != -1 and u.player == 0 and u.type != Witch)
      return true;
    c = cell(pos+Right+Right);
    u = unit (c.id);
    if (u.id != -1 and u.player == 0 and u.type != Witch)
      return true;
    c = cell(pos+Bottom+Bottom);
    u = unit (c.id);
    if (u.id != -1 and u.player == 0 and u.type != Witch)
      return true;
    return false;
  }*/
  
  inline bool knighted(Pos pos) {
    for (int i = 0; i < 8; i++){
        Cell c = cell(pos+knight_movements[i]);
        if (c.id != -1) {
          Unit u = unit(c.id);
          if (u.player != 0 and u.type == Knight)
            return true;
        }
    }

   return false;
  }

  inline bool knighted2(Pos pos,int& health) {
    for (int i = 0; i < 8; i++){
        Cell c = cell(pos+knight_movements[i]);
        if (c.id != -1) {
          Unit u = unit(c.id);
          if (u.player != 0 and u.type == Knight) {
            health = u.health;
            return true;
          }
        }
    }

   return false;
  }


  inline bool check_farmer_escape(Pos pos,UnitType unitType, int health) {
    if (unitType == Farmer) {
      Cell c = cell(pos);
      if (c.type == Wall)
        return false;
      if (c.haunted)
        return false;
      /*if (extra_haunted(pos)) // !
        return false;*/
      if (c.id != -1)
        return false;
      /*if (knighted(pos))
        return false;*/
      return true;
    }
    else if (unitType == Knight){
      //return false;
      Cell c = cell(pos);
      if (c.type == Wall)
        return false;
      if (c.haunted)
        return false;
      /*if (extra_haunted(pos)) // !
        return false;*/
      if (c.id != -1) {
        Unit u = unit(c.id);
        if (u.player == 0)
          return false;
        if (u.type == Witch)
          return false;
        if (u.type == Knight) 
          return false;
        if (u.type == Farmer) 
          return true;

      }
      //int health_en;
      //if (knighted2(pos,health_en) and 1.5*health < health_en)
      /*if (knighted(pos) and health < 60)
        return false;*/
      return true;
    }
  }

  inline bool check_targetable_escape(Pos pos,UnitType unitType, int health) {
    /*if (not extra_haunted(pos) and not knighted(pos))
      return true;*/
    Cell c = cell(pos);
    if (not c.haunted)
      return true;
    else return false;
  }

  /*

  inline bool check_farmer(Pos pos) {
    Cell c = cell(pos);
    if (c.type == Wall)
        return false;
    if (c.haunted)
        return false;
    if (c.id != -1)
        return false;
    if (knighted(pos))
      return false;
    return true;
  }

    inline bool check_targetable(Pos pos) {
    Cell c = cell(pos);
    if (c.owner != 0)
      return true;
    else
      return false;
  }


  */




  


   inline bool check_farmer(Pos pos,UnitType unitType, int health) {
    if (unitType == Farmer) {
      Cell c = cell(pos);
      if (c.type == Wall)
        return false;
      if (c.haunted)
        return false;
      if (extra_haunted(pos)) // !
        return false;
      if (c.id != -1)
        return false;
      if (knighted(pos))
        return false;
      return true;
    }
    else if (unitType == Knight){
      //return false;
      Cell c = cell(pos);
      if (c.type == Wall)
        return false;
      if (c.haunted)
        return false;
      if (extra_haunted(pos)) // !
        return false;
      if (c.id != -1) {
        Unit u = unit(c.id);
        if (u.player == 0)
          return false;
        if (u.type == Witch)
          return false;
        if (u.type == Knight) 
          return true;
        if (u.type == Farmer) 
          return true;

      }
      //int health_en;
      //if (knighted2(pos,health_en) and 1.5*health < health_en)
      /*if (knighted(pos) and health < 60)
        return false;*/
      return true;
    }
    else if (unitType == Witch) {
      Cell c = cell(pos);
      if (c.type == Wall)
        return false;
      if (c.id != -1) {
        Unit u = unit(c.id);
        if (u.player == 0)
          return false;
        if (u.type == Witch)
          return false;
        return true;
      }
      if (self_haunted(pos) > 1 and round() > 20) { // (abans self_haunted > 0) ROUND: clauissim!!! > 20 EP EP
        return false;
      }
      /*if (self_haunted(pos) > 5 and round() <= 20) {
        return false;
      }*/
      return true;
    }
    
    else
      return false;
  }
  
  inline bool check_targetable(Pos pos,UnitType unitType, int health) {
    if (unitType == Farmer) {
    Cell c = cell(pos);
    if (c.owner != 0)
      return true;
    else
      return false;
    }
    else if (unitType == Knight) {
      Cell c = cell(pos);
      if (c.id != -1) {
        Unit u = unit(c.id);
        if (u.player == 0)
          return false;
        else {
          if (u.type == Farmer)
            return true;
          else if (u.type == Knight) {
            return true;
           /*if (health > u.health)
              return true;
            else
              return false;*/
          }
          else
            return false;
        }
      }
      else
        return false;
    }
    else if (unitType == Witch) {
      /*Cell c = cell(pos);
      if (c.id != -1) {
        Unit u = unit(c.id);
        if (u.player == 0)
          return false;
        else if (u.type == Witch)
          return false;
        else if (u.type == Knight)
          return true;
        
        //else if (u.type == Farmer)
          //return true;
        //else
          //return true;
          
      }*/
      /*if (round() <= 40 and other_haunted(pos) > 4)
        return true;*/
      /*if (round() > 40 and other_haunted(pos) > 0)
        return true;*/
      if (other_haunted(pos) > 1) // > = 0 ?
        return true;
    }
    return false;
  }

 /*inline bool check_knight_targetable(Pos pos) {
    Cell c = cell(pos);
    if (c.id != -1 and unit(c.id).player != 0)
      return true;
    else
      return false;
  }

  inline bool check_knight(Pos pos) {
    Cell c = cell(pos);
    if (c.type == Wall)
        return false;
    if (c.haunted)
        return false;
    if (c.id != -1)
        return false;
    if (knighted(pos))
      return false;
    return true;
  }*/


  /*inline bool bfs_farmer(int id) {
    Unit u = unit(id);
    queue<Pos> q;
    q.push(u.pos);
    map<Pos,Pos> m; // path: key child, info parent
    m.insert(make_pair(u.pos,u.pos));
    int c = 0;
    set<Pos> s_visited;
    
    while (not q.empty()) {
      Pos pos = q.front(); 
      s_visited.insert(pos);
      q.pop();
      for(int i = 0; i < 4; i++) {
        if (check_farmer(pos+farmer_movements[i])) {
          if (check_targetable(pos+farmer_movements[i])) {
            //FOUND
            m.insert(make_pair(pos+farmer_movements[i],pos));
            Pos pos_dir = pos+farmer_movements[i];
            Pos pos_aux;
            while (pos_dir != u.pos) {
              pos_aux = pos_dir;
              pos_dir = m[pos_dir];
            }
            if (u.pos+Left == pos_aux) {
              command(id,Left);
            }
            else if (u.pos+Top == pos_aux) {
              command(id,Top);
            }
            else if (u.pos+Right == pos_aux) {
              command(id,Right);
            }
            else if (u.pos+Bottom == pos_aux) {
              command(id,Bottom);
            }
            return true;
          }
          else {
            // if (m.find(pos+farmer_movements[i]) == m.end()) {
            if (s_visited.find(pos+farmer_movements[i]) == s_visited.end()) {
              q.push(pos+farmer_movements[i]);
              m.insert(make_pair(pos+farmer_movements[i],pos));
            }
          }
        }
      }
    }
    command(id,None);
    return false;
  }*/

  /*
  inline bool bfs_farmer(int id) {
    Unit u = unit(id);
    queue<Pos> q;
    q.push(u.pos);
    map<Pos,Pos> m; // path: key child, info parent
    m.insert(make_pair(u.pos,u.pos));
    int c = 0;
    set<Pos> s_visited;
    
    while (not q.empty()) {
      Pos pos = q.front(); 
      s_visited.insert(pos);
      q.pop();
      for(int i = 0; i < 4; i++) {
        if (check_farmer(pos+farmer_movements[i])) {
          if (check_targetable(pos+farmer_movements[i])) {
            //FOUND
            m.insert(make_pair(pos+farmer_movements[i],pos));
            Pos pos_dir = pos+farmer_movements[i];
            Pos pos_aux;
            while (pos_dir != u.pos) {
              pos_aux = pos_dir;
              pos_dir = m[pos_dir];
            }
            if (u.pos+Left == pos_aux) {
              command(id,Left);
            }
            else if (u.pos+Top == pos_aux) {
              command(id,Top);
            }
            else if (u.pos+Right == pos_aux) {
              command(id,Right);
            }
            else if (u.pos+Bottom == pos_aux) {
              command(id,Bottom);
            }
            return true;
          }
          else {
            // if (m.find(pos+farmer_movements[i]) == m.end()) {
            if (s_visited.find(pos+farmer_movements[i]) == s_visited.end()) {
              q.push(pos+farmer_movements[i]);
              m.insert(make_pair(pos+farmer_movements[i],pos));
            }
          }
        }
      }
    }
    command(id,None);
    return false;
  }*/  
/*
    inline bool bfs_knight(int id) {
    Unit u = unit(id);
    queue<Pos> q;
    q.push(u.pos);
    map<Pos,Pos> m; // path: key child, info parent
    m.insert(make_pair(u.pos,u.pos));
    int c = 0;
    set<Pos> s_visited;
    
    while (not q.empty()) {
      Pos pos = q.front(); 
      s_visited.insert(pos);
      q.pop();
      for(int i = 0; i < 8; i++) {
        if (check_knight(pos+knight_movements[i])) {
          if (check_knight_targetable(pos+knight_movements[i])) {
            //FOUND
            m.insert(make_pair(pos+knight_movements[i],pos));
            Pos pos_dir = pos+knight_movements[i];
            Pos pos_aux;
            while (pos_dir != u.pos) {
              pos_aux = pos_dir;
              pos_dir = m[pos_dir];
            }
            if (u.pos+Left == pos_aux) {
              command(id,Left);
            }
            else if (u.pos+Top == pos_aux) {
              command(id,Top);
            }
            else if (u.pos+Right == pos_aux) {
              command(id,Right);
            }
            else if (u.pos+Bottom == pos_aux) {
              command(id,Bottom);
            }
            else if (u.pos+BR == pos_aux) {
              command(id,BR);
            }
            else if (u.pos+BR == pos_aux) {
              command(id,BR);
            }
            else if (u.pos+RT == pos_aux) {
              command(id,RT);
            }
            else if (u.pos+TL == pos_aux) {
              command(id,TL);
            }
            else if (u.pos+LB== pos_aux) {
              command(id,LB);
            }

            return true;
          }
          else {
            // if (m.find(pos+farmer_movements[i]) == m.end()) {
            if (s_visited.find(pos+knight_movements[i]) == s_visited.end()) {
              q.push(pos+knight_movements[i]);
              m.insert(make_pair(pos+knight_movements[i],pos));
            }
          }
        }
      }
    }
    command(id,None);
    return false;
  }  
*/

  void log(int id, UnitType unitType, int health) {
    cerr << "Sóc " << id << endl;
    for (int i = 0; i < 37; i++) {
      for (int j = 0; j < 37; j++) {
        Cell c = cell(i,j);
        if (c.id == id)
          cerr << "X ";
        else {
          Pos pos(i,j);
          bool cf = check_farmer(pos,unitType,health);
          bool ct = check_targetable(pos,unitType,health);
          if (cf and ct) cerr << "2 ";
          else if (cf and not ct) cerr << "1 ";
          else if (not cf and not ct) cerr << "0 ";
          else cerr << "W ";
        }
      }
      cerr << endl;
    }
  }

  inline bool bfs_farmer(int id) {
    Unit u = unit(id);
    if (u.type != Witch) {
      /*if (u.type == Farmer and u.health < 40) {
        command(id,None);
        return false;
      }*/
      if (u.type == Knight and u.health < 20) {
        command(id,None);
        return false;
      }
    }
    queue<Pos> q;
    q.push(u.pos);

    map<Pos,Pos> m; // path: key child, info parent
    m.insert(make_pair(u.pos,u.pos));
    int c = 0;
    set<Pos> s_visited;
    UnitType unitType = u.type;
    int n = 0;
    vector<Dir> mov(8);
    if (u.type == Farmer or u.type == Witch) {
      n = 4;
      vector<Dir> mov_aux(n);
      for (int i = 0; i < n; i++)
        mov_aux[i] = farmer_movements[i];
      vector<int> randp = random_permutation(n);
      for (int i = 0; i < n; i++)
        mov[randp[i]] = mov_aux[i];
    }
    else if (u.type == Knight) {
      n = 8;
      vector<int> randp = random_permutation(n);
      for (int i = 0; i < n; i++)
        mov[randp[i]] = farmer_movements[i];

    }
    while (not q.empty()) {
      //if (q.size() > 6000) log(id,unitType,u.health);
      //cerr << id << " " << q.size() << endl;
      Pos pos = q.front(); 
      s_visited.insert(pos);
      q.pop();
      for(int i = 0; i < n; i++) {
        if (check_farmer(pos+mov[i],unitType,u.health)) {
        //if (check_farmer(pos+farmer_movements[i])) {
          if (check_targetable(pos+mov[i],unitType,u.health)) {
          //if (check_targetable(pos+farmer_movements[i])) {
            //FOUND
            m.insert(make_pair(pos+mov[i],pos));
            Pos pos_dir = pos+mov[i];
            Pos pos_aux;
            while (pos_dir != u.pos) {
              pos_aux = pos_dir;
              pos_dir = m[pos_dir];
            }
            if (u.pos+Left == pos_aux) {
              command(id,Left);
            }
            else if (u.pos+Top == pos_aux) {
              command(id,Top);
            }
            else if (u.pos+Right == pos_aux) {
              command(id,Right);
            }
            else if (u.pos+Bottom == pos_aux) {
              command(id,Bottom);
            }
            else if (unitType == Knight) {
              if (u.pos+BR == pos_aux) {
                command(id,BR);
              }
              else if (u.pos+RT == pos_aux) {
                command(id,RT);
              }
              else if (u.pos+TL == pos_aux) {
                command(id,TL);
              }
              else if (u.pos+LB == pos_aux) {
                command(id,LB);
              }
            }
            return true;
          }
          else {
            // if (m.find(pos+farmer_movements[i]) == m.end()) {
            if (s_visited.find(pos+mov[i]) == s_visited.end()) {
              s_visited.insert(pos+mov[i]); // no necessari pels farmers, sí pels knights
              q.push(pos+mov[i]);
              m.insert(make_pair(pos+mov[i],pos));
            }
          }
        }
      }
    }
    bool b;
    if (extra_haunted(u.pos) or knighted(u.pos)) {
      cerr << "YEP" << endl;
      b = bfs_escape(id);
    }
    
    cerr << "Sóc " << id << " a la ronda " << round() << " i sóc " << u.type << endl;
    if (not b)
      command(id,None);
    return false;
  }





  bool witch_initial_movement(int id) {
    Unit u = unit(id);
    Pos pos = u.pos+Right;
    Cell c = cell(pos);
    if (c.type != Wall) {
      command(id,Right);
      return true;
    }
    else {
      pos = u.pos+Bottom;
      c = cell(pos);
      if (c.type != Wall) {
        command(id,Bottom);
        return true;
      }
      else
        return false;
    }
  }











    inline bool bfs_escape(int id) {
    Unit u = unit(id);
    queue<Pos> q;
    q.push(u.pos);

    map<Pos,Pos> m; // path: key child, info parent
    m.insert(make_pair(u.pos,u.pos));
    int c = 0;
    set<Pos> s_visited;
    UnitType unitType = u.type;
    int n = 0;
    vector<Dir> mov(8);
    if (u.type == Farmer or u.type == Witch) {
      n = 4;
      vector<Dir> mov_aux(n);
      for (int i = 0; i < n; i++)
        mov_aux[i] = farmer_movements[i];
      vector<int> randp = random_permutation(n);
      for (int i = 0; i < n; i++)
        mov[randp[i]] = mov_aux[i];
    }
    else if (u.type == Knight) {
      n = 8;
      vector<int> randp = random_permutation(n);
      for (int i = 0; i < n; i++)
        mov[randp[i]] = farmer_movements[i];

    }
    while (not q.empty()) {
      //if (q.size() > 6000) log(id,unitType,u.health);
      //cerr << id << " " << q.size() << endl;
      Pos pos = q.front(); 
      s_visited.insert(pos);
      q.pop();
      for(int i = 0; i < n; i++) {
        if (check_farmer_escape(pos+mov[i],unitType,u.health)) {
        //if (check_farmer(pos+farmer_movements[i])) {
          if (check_targetable_escape(pos+mov[i],unitType,u.health)) {
          //if (check_targetable(pos+farmer_movements[i])) {
            //FOUND
            m.insert(make_pair(pos+mov[i],pos));
            Pos pos_dir = pos+mov[i];
            Pos pos_aux;
            while (pos_dir != u.pos) {
              pos_aux = pos_dir;
              pos_dir = m[pos_dir];
            }
            if (u.pos+Left == pos_aux) {
              command(id,Left);
            }
            else if (u.pos+Top == pos_aux) {
              command(id,Top);
            }
            else if (u.pos+Right == pos_aux) {
              command(id,Right);
            }
            else if (u.pos+Bottom == pos_aux) {
              command(id,Bottom);
            }
            else if (unitType == Knight) {
              if (u.pos+BR == pos_aux) {
                command(id,BR);
              }
              else if (u.pos+RT == pos_aux) {
                command(id,RT);
              }
              else if (u.pos+TL == pos_aux) {
                command(id,TL);
              }
              else if (u.pos+LB == pos_aux) {
                command(id,LB);
              }
            }
            return true;
          }
          else {
            // if (m.find(pos+farmer_movements[i]) == m.end()) {
            if (s_visited.find(pos+mov[i]) == s_visited.end()) {
              s_visited.insert(pos+mov[i]); // no necessari pels farmers, sí pels knights
              q.push(pos+mov[i]);
              m.insert(make_pair(pos+mov[i],pos));
            }
          }
        }
      }
    }
    return false;
  }











  /**
   * Types and attributes for your player can be defined here.
   */

  vector<int> f;
  vector<int> k;
  vector<int> w;
  Dir knight_movements[8] = {Bottom,BR,Right,RT,Top,TL,Left,LB};
  //Dir farmer_movements[4] = {Left,Top,Right,Bottom};
  //Dir farmer_movements[4] = {Left,Top,Right,Bottom};
  Dir farmer_movements[8] = {Left,Top,Right,Bottom,BR,RT,TL,LB};

  /**
   * Play method, invoked once per each round.
   */

  virtual void play () {
    f = farmers(0);
    for (int i = 0; i < f.size(); i++)
        bfs_farmer(f[i]);
    k = knights(0);
    for (int i = 0; i < k.size(); i++)
        bfs_farmer(k[i]);
    w = witches(0);

    /*if (round() < 5) {
      for (int i = 0; i < w.size(); i++)
        witch_initial_movement(w[i]);
    }
    else*/
    for (int i = 0; i < w.size(); i++)
        bfs_farmer(w[i]);

  }

};


/**
 * Do not modify the following line.
 */
RegisterPlayer(PLAYER_NAME);
