#ifndef SHADER_H
#define SHADER_H

#include <QDebug>
#include <QOpenGLShader>
#include <QOpenGLShaderProgram>
#include <QString>

class Shader {
public:
	Shader(const QString& vertexSourcePath, const QString& fragmentSourcePath);
	~Shader();
	QOpenGLShaderProgram shaderProgram;









public:
	void use();
	
	
	void setMat4(const QString& name, const QMatrix4x4& value);

	void setInt(const QString& name, const GLint& value) {
		GLuint loc = shaderProgram.uniformLocation(name);
		shaderProgram.setUniformValue(loc, value);

	}

	void setFloat(const QString& name, const GLfloat& value);

	void setVec4(const QString& name, QVector4D& vec4d);
	
		
	void setVec3(const QString& name, QVector3D& vec3d);

};

#endif // SHADER_H