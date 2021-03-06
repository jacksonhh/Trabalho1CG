
GLuint chaoid,paredeid,windowid;

void swapRB(unsigned char & b, unsigned char & r);
unsigned char *  loadBMP_custom(const char * filename, unsigned int &width, unsigned int &height);
GLuint loadTex(unsigned char *Imagem,unsigned int ih,unsigned int iw);
void drawTexture(void);


void swapRB(unsigned char & b, unsigned char & r) {
	unsigned char x;
	x = r;
	r = b;
	b = x;
}

unsigned char *  loadBMP_custom(const char * filename, unsigned int &width, unsigned int &height) {
	// Data read from the header of the BMP file
	unsigned char header[54]; // Each BMP file begins by a 54-bytes header
	unsigned int dataPos;     // Position in the file where the actual data begins
	//unsigned int width, height;
	unsigned int imageSize;   // = width*height*3
	// Actual RGB data
	unsigned char * data;
	// Open the file
	FILE * file;
	file = fopen( filename, "rb");
	if (!file) { printf("Image could not be opened\n"); return 0; };
	if (fread(header, 1, 54, file) != 54) { // If not 54 bytes read : problem
		printf("Not a correct BMP file\n");
		return 0;
	}
	if (header[0] != 'B' || header[1] != 'M') {
		printf("Not a correct BMP file\n");
		return 0;
	}
	// Read ints from the byte array
	dataPos = *(int*)&(header[0x0A]);
	imageSize = *(int*)&(header[0x22]);
	width = *(int*)&(header[0x12]);
	height = *(int*)&(header[0x16]);
	// Some BMP files are misformatted, guess missing information
	if (imageSize == 0)    imageSize = width*height * 3; // 3 : one byte for each Red, Green and Blue component
	if (dataPos == 0)      dataPos = 54; // The BMP header is done that way
	// Create a buffer
	data = new unsigned char[imageSize];
	// Read the actual data from the file into the buffer
	fread(data, 1, imageSize, file);
	for (unsigned int i = 0; i < imageSize; i += 3) swapRB(data[i], data[i + 2]);
	//Everything is in memory now, the file can be closed
	fclose(file);
	return data;
}

GLuint loadTex(unsigned char *Imagem,unsigned int ih,unsigned int iw){
  GLuint textureId;

  glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
  glGenTextures(1, &textureId);
  glBindTexture (GL_TEXTURE_2D,textureId);
  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, iw, ih, 0,GL_RGB, GL_UNSIGNED_BYTE, Imagem);
  gluBuild2DMipmaps(textureId, GL_RGB, iw, ih, GL_RGB, GL_UNSIGNED_BYTE, Imagem);


  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);


	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

	glEnable(GL_TEXTURE_2D);

  return textureId;
}

void drawTexture(void){
	unsigned int ih=0, iw=0;
	unsigned char * imagem = NULL;
	glShadeModel(GL_SMOOTH);

  imagem = loadBMP_custom("floor2.bmp", iw, ih);
    chaoid = loadTex(imagem,ih,iw);

	imagem = loadBMP_custom("wall3.bmp", iw, ih);
  paredeid = loadTex(imagem,ih,iw);

  imagem = loadBMP_custom("window2.bmp", iw, ih);
  windowid = loadTex(imagem,ih,iw);

	/*imagem = loadBMP_custom("areia.bmp", iw, ih);
  areiaid = loadTex(imagem,ih,iw);*/


  delete imagem;
}
