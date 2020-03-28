#include "SceneManager.h"

using namespace rapidjson;
using namespace std;

void SceneManager::LoadScene()
{
	FILE* fp = fopen("Scenes/scene1.json", "rb");

	char readBuffer[65536];
	FileReadStream is(fp, readBuffer, sizeof(readBuffer));

	Document d;
	d.ParseStream(is);

	assert(d.IsObject());
	assert(d.HasMember("hello"));
	assert(d["hello"].IsString());
	printf("hello = %s\n", d["hello"].GetString());

	assert(d.HasMember("customer"));
	assert(d["customer"].IsArray());

	const Value& customer = d["customer"];
	assert(customer.IsArray());
	for (SizeType i = 0; i < customer.Size(); i++) // Uses SizeType instead of size_t
	{
		if (customer[i].IsObject())
		{
			const Value& temp = customer[i];
			if (temp.HasMember("id"))
			{
				if (temp["id"].IsString())
				{
					printf("customer[%d] = %s\n", i, temp["id"].GetString());
				}
				else if (temp["id"].IsInt())
				{
					printf("customer[%d] = %d\n", i, temp["id"].GetInt());
				}

			}
			else if (temp.HasMember("name"))
			{
				printf("customer[%d] = %s\n", i, temp["name"].GetString());
			}

		}
	}
	fclose(fp);
}



