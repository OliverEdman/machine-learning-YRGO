Skapa en fil döpt main.cpp. Anta att du har följande vektor:

std::vector<std::uint8_t> v1{1U, 2U, 3U};

Iterera genom vektorn och skriv ut dess innehåll på hexadecimal form via:

a) Index.
b) Range-baserad for-loop.
c) C++-iterator.


Tips: Heltal kan skrivas ut på hexadecimal form med std::printf():

Skriver ut '03'.
std::printf("%02X", 3U);

Skriver ut '0x0F':
std::printf("0x%02X", 5U);


