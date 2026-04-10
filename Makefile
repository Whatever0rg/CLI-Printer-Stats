default: build

build: clean
	g++ main.cpp -o fetch
	./fetch

clean:
	rm -rf fetch
	rm -rf response.json

test: build
    ./curl https://freegeoip.app/json/