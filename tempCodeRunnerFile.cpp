

    cout << v.size() << endl;    //output : 4
    cout << v.capacity() << endl; //output : 10 (컴파일 환경에 따라 달라질 수 있음)

    v.reserve(6);
    cout << v.capacity() << endl; //output : 6
    cout << v.max_size() << endl; //output : 1073741823(시스템 성능에 따라 달라질 수 있음)

    v.shrink_to_fit();
    cout << v.capacity() << endl; //output : 4

    cout << v.empty() << endl; //output : false
    v.clear();
    cout << v.empty() << endl; //output : true​