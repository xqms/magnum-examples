#ifndef Magnum_Examples_ShadowReceiverShader_h
#define Magnum_Examples_ShadowReceiverShader_h
/*
    This file is part of Magnum.

    Original authors — credit is appreciated but not required:

        2010, 2011, 2012, 2013, 2014, 2015, 2016, 2017 —
            Vladimír Vondruš <mosra@centrum.cz>
        2016 — Bill Robinson <airbaggins@gmail.com>

    This is free and unencumbered software released into the public domain.

    Anyone is free to copy, modify, publish, use, compile, sell, or distribute
    this software, either in source code form or as a compiled binary, for any
    purpose, commercial or non-commercial, and by any means.

    In jurisdictions that recognize copyright laws, the author or authors of
    this software dedicate any and all copyright interest in the software to
    the public domain. We make this dedication for the benefit of the public
    at large and to the detriment of our heirs and successors. We intend this
    dedication to be an overt act of relinquishment in perpetuity of all
    present and future rights to this software under copyright law.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
    THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
    IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
    CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#include <Magnum/AbstractShaderProgram.h>
#include <Magnum/Shaders/Generic.h>

namespace Magnum { namespace Examples {

/** @brief Shader that can synthesize shadows on an object */
class ShadowReceiverShader: public AbstractShaderProgram {
    public:
        typedef Shaders::Generic3D::Position Position;
        typedef Shaders::Generic3D::Normal Normal;

        explicit ShadowReceiverShader(Int numShadowLevels);

        /**
         * @brief Set transformation and projection matrix
         *
         * Matrix that transforms from local model space -> world space ->
         * camera space -> clip coordinates (aka model-view-projection matrix).
         */
        ShadowReceiverShader& setTransformationProjectionMatrix(const Matrix4& matrix);

        /**
         * @brief Set model matrix
         *
         * Matrix that transforms from local model space -> world space (used
         * for lighting).
         */
        ShadowReceiverShader& setModelMatrix(const Matrix4& matrix);

        /**
         * @brief Set shadowmap matrices
         *
         * Matrix that transforms from world space -> shadow texture space.
         */
        ShadowReceiverShader& setShadowmapMatrices(Containers::ArrayView<const Matrix4> matrices);

        /** @brief Set world-space direction to the light source */
        ShadowReceiverShader& setLightDirection(const Vector3& vector3);

        /** @brief Set shadow map texture array */
        ShadowReceiverShader& setShadowmapTexture(Texture2DArray& texture);

        /**
         * @brief Set thadow bias uniform
         *
         * Normally it wants to be something from 0.0001 -> 0.001.
         */
        ShadowReceiverShader& setShadowBias(Float bias);

    private:
        enum: Int { ShadowmapTextureLayer = 0 };

        Int _modelMatrixUniform,
            _transformationProjectionMatrixUniform,
            _shadowmapMatrixUniform,
            _lightDirectionUniform,
            _shadowBiasUniform;
};

}}

#endif
