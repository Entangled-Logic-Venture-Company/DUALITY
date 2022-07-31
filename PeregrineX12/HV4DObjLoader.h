#pragma once

#include <winrt/Windows.Storage.h>

#include "winrt/HV4DDUALITY.HV4DTensors.h"

#include "Generated Files/HV4DLoaders.HV4DObjLoader.g.h"

namespace winrt::HV4DLoaders::implementation
{
    struct HV4DObjLoader : HV4DObjLoaderT<HV4DObjLoader>
    {
    public:
        HV4DObjLoader() = default;

        virtual Windows::Foundation::Collections::IVector<HV4DDUALITY::HV4DTensors::HV4DTriangle> 
            LoadMeshFromFile(hstring);

    private:
        void ExtractVertexFromLine(std::wstring);
        void ExtractTextCoordFromLine(std::wstring);
        void ExtractVertexNormalFromLine(std::wstring);
        void MakeFaces(std::wstring);

        std::vector<HV4DDUALITY::HV4DTensors::HV4DVertexCoord> oVertexCoordList{};
        std::vector<HV4DDUALITY::HV4DTensors::HV4DTextCoord> oTextCoordList{};
        std::vector<HV4DDUALITY::HV4DTensors::HV4DVertexNormal> oVertexNormalList{};

        Windows::Foundation::Collections::IVector<HV4DDUALITY::HV4DTensors::HV4DTriangle> oInputBuffer{
            winrt::single_threaded_vector<HV4DDUALITY::HV4DTensors::HV4DTriangle>() };

        UINT number_of_objects{ 0 };

    private:
        Windows::Foundation::Collections::IVector<hstring> ReadFromObjAsync(std::wstring);
        
        void CreateDebugFileAsync(std::wofstream**, std::wstring);
        
        void WriteDebugFileAsync(std::wofstream**, std::wstring);

    };

}

namespace winrt::HV4DLoaders::factory_implementation
{
    struct HV4DObjLoader : HV4DObjLoaderT<HV4DObjLoader, implementation::HV4DObjLoader>
    {

    };

}
