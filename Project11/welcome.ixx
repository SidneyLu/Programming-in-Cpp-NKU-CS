//һ���򵥵�module����ʾ��
export module welcome;

//��ͷ��Ԫ��ʽ�����׼��ģ�飬����������ͷ�ļ��������������������õ�Ŀǰ����֧��
//������#includeͷ�ļ��Ĵ����importģ��Ĵ���ϲ�
import <iostream>;
import <string>;
import <vector>;


//Ŀǰ��ģ�黯�ı�׼�⣨ʵ���ԣ�
//��Ŀ->����->��������->C/C++->����->����ʵ���Ե�C++��׼��ģ��
import std.core;      //��������֧��
import std.filesystem;//�ļ�ϵͳ֧��
import std.memory;    //����ָ����ڴ����֧��
import std.regex;     //������ʽ֧��
import std.threading;    //���߳�֧��

//Clang���������� import std; ������������׼��ģ��


/*
	�ڽ����ڱ�׼��C++�У�Ҳ�п��ܼ���export�ؼ��֣�����ʱ��export����ģ�壬���ڵ���ģ�嶨���Ա��ܲ�ɶ���ļ���
	���������ʵ�ָ��ӣ�ʵ���м���û���㷺֧�֡�
*/

/*
	���޷�����ģ����δexport�����ݣ���ͷ�ļ��е�һ�п�����#include֮����ʣ�������ͷ�ļ��ж�����౾��ķ�װ����
	ͬʱimportģ��������#includeͷ�ļ���������˳����ظ����壬����˵#pragma once��
*/

export std::string greetingsO(){
	return "Hello, welcome to C++20 modules!\nExport a single function.";
}

export {
	std::string greetingsI() {
		return "Hello, welcome to C++20 modules!\nExport multiple functions inside an export block.";
	}
}


/*
	������Ӧ������Ϊʲô�ڴ����ִ�C++������Ŀ�в�����ʹ��using namespace std;�˰�!
	��Ϊ�����std�����ռ��е����з��Ŷ����뵽��ǰ�����򣬵���������ͻ�ʹ���ɶ��Խ��͡�
	����STL�е�vector�Ǹ����Ե���̬�����õ�������ĳЩ����������е�vector�Ǹ���ѧ�����࣬
	������ͻ�ͻ�������ӡ�
*/

export namespace test1 {
	std::string greetingsN() {
		return "Hello, welcome to C++20 modules!\nCall a function inside an exported namespace.";
	}
}

namespace test2 {
	export std::string greetingsM() {
		return "Hello, welcome to C++20 modules!\nExport a function inside an unexported namespace.";
	}//������namespace�л���δ������������Ա����ô���ǲ��ɷ��ʡ�
}

