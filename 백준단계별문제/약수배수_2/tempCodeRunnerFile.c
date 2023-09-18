scanf("%lld %lld", &iFirst,&iSecond);
    lcd = find_gcd(iFirst,iSecond);
    lcm = iFirst * iSecond / lcd;    
    printf("%lld \n",lcm);   