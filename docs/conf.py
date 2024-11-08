# Configuration file for the Sphinx documentation builder.
#
# For the full list of built-in configuration values, see the documentation:
# https://www.sphinx-doc.org/en/master/usage/configuration.html

# -- Project information -----------------------------------------------------
# https://www.sphinx-doc.org/en/master/usage/configuration.html#project-information

import os
import sys

project = "evmspec"
copyright = "2024, BobTheBuidler"
author = "BobTheBuidler"

# -- General configuration ---------------------------------------------------
# https://www.sphinx-doc.org/en/master/usage/configuration.html#general-configuration

extensions = [
    "sphinx.ext.autodoc",
    "sphinx.ext.napoleon",
    "sphinx.ext.intersphinx",
    "sphinx.ext.viewcode",
]

templates_path = ["_templates"]
exclude_patterns = ["_build", "Thumbs.db", ".DS_Store"]

# Looks for objects in documentation of external libraries
intersphinx_mapping = {
    "msgspec": ("https://jcristharif.com/msgspec/", None),
    "python": ("https://docs.python.org/3", None),
}

# -- Options for HTML output -------------------------------------------------
# https://www.sphinx-doc.org/en/master/usage/configuration.html#options-for-html-output

html_theme = "sphinx_rtd_theme"
html_static_path = ["_static"]

autodoc_default_options = {
    "members": True,
    "special-members": True,
    "inherited-members": True,
    "undoc-members": True,
    "member-order": "groupwise",
    # hide private methods that aren't relevant to us here
    # "exclude-members": ",".join([]),
}

autodoc_typehints = "description"
# Don't show class signature with the class' name.
autodoc_class_signature = "separated"

automodule_generate_module_stub = True

sys.path.insert(0, os.path.abspath("./evmspec"))
